/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:28:36 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/26 13:05:11 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file, int mode)
{
	if (mode == 0)
	{
		if (access(file, F_OK))
		{
			write (1, "File isn't found\n", 17);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return(open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777));
}

// void	secondcmd(char *cmd, char **env, int i, int fdout)
// {
// 	char	**argv;
// 	char	*command;
	
// 	argv = ft_split(cmd, ' ');
// 	if (find_colon(argv[0], '/') > -1)
// 		command = argv[0];
// 	else
// 		command = command_path(argv[0], env);
	
// 	if(i != 2)
// 	{
// 		execve(command, argv, env);		
		
// 	}else{
// 		int pid = fork();
// 		if(!pid)
// 		{
// 			dup2(STDOUT_FILENO, fdout);
// 			close (STDOUT_FILENO);
// 			execve(command, argv, env);
// 		}
// 	}

// 	write(2, "Command isn't found\n", 20);
// 	exit(127);
// }

// void	firstcmd(char *cmd, char **env, int fdin, int fdout)
// {
// 	pid_t	pid;
// 	int		pfd[2];
	
// 	pipe(pfd);
// 	pid = fork();
// 	if (pid)
// 	{
// 		close(pfd[1]);
// 		dup2(pfd[0], 0);
// 		// waitpid(pid, NULL, 0);
// 	}
// 	else
// 	{	
// 		close(pfd[0]);
// 		dup2(pfd[1], 1);
// 		if (fdin == 0)
// 			exit(1);
// 		else
// 		{
// 			secondcmd(cmd, env, 1, fdout);
// 			waitpid(pid, NULL, 0);
// 		}	
// 	}	
// }

// int	main(int ac, char **av, char **env)
// {	
// 	int	fdin = 0;
//  	int	fdout = 0;
	
// 	if (ac == 5)
// 	{
// 		fdin = ft_open(av[1], 0);
// 		fdout = ft_open(av[4], 1);
// 		dup2(fdin, 0);
// 		dup2(fdout, 1);
		
// 		firstcmd(av[2], env, fdin, fdout);
// 		secondcmd(av[3], env, 2, fdout);
// 	}
// 	else
// 		write(2, "It must take 4 arguments\n", 25);

// 	close(fdout);
// 	close(fdin);
// 	return 1;
// }

char	*ft_path(char *cmd, char **env)
{
	char	**argv;
	char	*command;
	
	argv = ft_split(cmd, ' ');
	if (find_colon(argv[0], '/') > -1)
		command = argv[0];
	else
		command = command_path(argv[0], env);
	return(command);
}

char	**ft_commamd(char *cmd)
{
	char	**argv;
	
	argv = ft_split(cmd, ' ');
	return(argv);
}

int main(int ac, char **av, char **env)
{
	int		pfd[2];
	char	**command;
	char	*path;
	pid_t	pid1;
	pid_t	pid2;
	
	command = 0;
	path = 0;
	pfd[0] = 0;
	pfd[1] = 0;
	if(ac == 5)
	{	
		pfd[0] = ft_open(av[1], 0);
		pfd[1] = ft_open(av[4], 1);
		dup2(pfd[0], STDIN_FILENO);
		dup2(pfd[1], STDOUT_FILENO);
		pipe(pfd);
		pid1 = fork();
		if(pid1 == 0)
		{
			close(pfd[0]);
			dup2(pfd[1], STDOUT_FILENO);
			close(pfd[1]);
			command = ft_commamd(av[2]);
			path = ft_path(av[2], env);
			execve(path, command, env);
			perror("command");
			exit(1);
		}
		pid2 = fork();
		if(pid2 == 0)
		{
			close(pfd[1]);
			dup2(pfd[0], STDIN_FILENO);
			close(pfd[0]);
			command = ft_commamd(av[3]);
			path = ft_path(av[3], env);
			execve(path, command, env);
			perror("command2");
			exit(1);
		}
		close(pfd[0]);
		close(pfd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return 0;
	}
}
///////////
char	*ft_path(char *cmd, char **env)
{
	char	**argv;
	char	*command;

	argv = ft_split(cmd, ' ');
	if (find_colon(argv[0], '/') > -1)
		command = argv[0];
	else
		command = command_path(argv[0], env);
	return (command);
}

void	first(int pfd_in, int pfd_out, char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = ft_path(cmd, env);
	close(pfd_in);
	dup2(pfd_out, STDOUT_FILENO);
	close(pfd_out);
	execve(path, command, env);
	perror("command");
	exit(1);
}

void	second(int pfd_in, int pfd_out, char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = ft_path(cmd, env);
	close(pfd_out);
	dup2(pfd_in, STDIN_FILENO);
	close(pfd_in);
	execve(path, command, env);
	perror("command2");
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac == 5)
	{	
		pfd[0] = ft_open(av[1], 0);
		pfd[1] = ft_open(av[4], 1);
		dup2(pfd[0], STDIN_FILENO);
		dup2(pfd[1], STDOUT_FILENO);
		pipe(pfd);
		pid1 = fork();
		if (pid1 == 0)
			first(pfd[0], pfd[1], av[2], env);
		pid2 = fork();
		if (pid2 == 0)
			second(pfd[0], pfd[1], av[3], env);
		close(pfd[0]);
		close(pfd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return (0);
	}
}
