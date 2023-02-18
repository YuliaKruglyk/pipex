/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:59:18 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/08 14:19:42 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s || fd < 0)
		write(fd, s, ft_strlen(s));
}

// int main ()
// {
// 	char str[] = "check";
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }
