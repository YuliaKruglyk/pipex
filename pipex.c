/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:28:36 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/11/09 17:35:58 by ykruhlyk         ###   ########.fr       */
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
		return (open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777));
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

void	parent(char **av, char **env)
{
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;

	pfd[0] = ft_open(av[1], 0);
	pfd[1] = ft_open(av[4], 1);
	dup2(pfd[0], STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close (pfd[1]);
	close(pfd[0]);
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
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
		parent(av, env);
	else
		write(2, "It must take 4 arguments\n", 25);
	return (0);
}
