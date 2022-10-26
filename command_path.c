/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:45:29 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/22 20:32:37 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int find_colon(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == c)
			return(i);
		i++;
	}
	return(-1);
}

char *ft_strndup(char *s1, unsigned int n)
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	while  (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return(s2);
}

char	*cmdjoin(char *path, char *bin)
{
	int		i;
	int		j;
	char	*command;
	
	i = 0;
	j = 0;
	command = malloc(sizeof(char) * (find_colon(path, 0) + find_colon(bin, 0) + 2));
	while(path[j])
	{
		command[i] = path[j];
		i++;
		j++;
	}
	command[i] = '/';
	i++;
	j = 0;
	while (bin[j])
	{
		command[i] = bin[j];
		i++;
		j++;
	}
	command[i] = '\0';
	return(command);
}

char *command_path(char *cmd, char **env)
{
	int		i;
	char	*env_path;
	char	*command;
	char	*path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return(cmd);
	env_path = env[i] + 5;
	while (env_path && find_colon(env_path, ':') != -1)
	{
		path = ft_strndup(env_path, find_colon(env_path, ':'));
		command = cmdjoin(path, cmd);
		free(path);
		if(access(command, F_OK) == 0)
			return(command);
		free(command);
		env_path += find_colon(env_path, ':') + 1;

	}
	return(cmd);
}

