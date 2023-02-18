/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:45:29 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/11/08 09:57:07 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_colon(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *s1, unsigned int n)
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*cmdjoin(char *path, char *bin)
{
	int		i;
	int		j;
	char	*command;

	i = 0;
	j = 0;
	command = malloc(sizeof(char) * (find_colon(path, 0)
				+ find_colon(bin, 0) + 2));
	if (!command)
		return (NULL);
	while (path[j])
		command[i++] = path[j++];
	command[i] = '/';
	i++;
	j = 0;
	while (bin[j])
		command[i++] = bin[j++];
	command[i] = '\0';
	return (command);
}

char	*command_path(char *cmd, char **env)
{
	int		i;
	char	*env_path;
	char	*command;
	char	*path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	env_path = env[i] + 5;
	while (env_path && find_colon(env_path, ':') != -1)
	{
		path = ft_strndup(env_path, find_colon(env_path, ':'));
		command = cmdjoin(path, cmd);
		free(path);
		if (access(command, F_OK) == 0)
			return (command);
		free (command);
		env_path += find_colon(env_path, ':') + 1;
	}
	return (cmd);
}

char	*ft_path(char *cmd, char **env)
{
	char	**argv;
	char	*command;

	argv = ft_split(cmd, ' ');
	printf("%s\n", argv[0]);
	if (find_colon(argv[0], '/') > -1)
		command = argv[0];
	else
		command = command_path(argv[0], env);
	return (command);
}
