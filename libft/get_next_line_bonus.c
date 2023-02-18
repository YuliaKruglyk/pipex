/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:54:02 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/24 09:57:08 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_fd(int fd, char *line)
{
	char	*buf;
	int		fd_r;
	char	*joined;

	if (!line)
		line = ft_calloc(1, 1);
	fd_r = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (fd_r > 0 && !(ft_strchr(buf, '\n')))
	{
		fd_r = read(fd, buf, BUFFER_SIZE);
		if (fd_r < 0)
		{	
			free(buf);
			return (NULL);
		}
		buf[fd_r] = '\0';
		joined = ft_strjoin(line, buf);
		free (line);
		line = joined;
	}
	free(buf);
	return (line);
}

char	*return_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc((i + 1 + (buf[i] == '\n')), sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*following(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
	{
		line[j] = buf[i];
		j++;
		i++;
	}
	free(buf);
	return (line);
}

char	*get_next_line_b(int fd)
{
	static char	*buf[MAX_INT];
	char		*line;

	if ((read(fd, buf, 0)) || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = read_fd(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = return_line(buf[fd]);
	buf[fd] = following(buf[fd]);
	return (line);
}
