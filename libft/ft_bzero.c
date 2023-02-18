/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:55:14 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/01 14:24:13 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tem;

	i = 0;
	tem = (unsigned char *) s;
	while (n > i)
	{
		tem[i] = 0;
		i++;
	}
	s = tem;
}

// int	main(void)
// {
//    unsigned char	src[15]="1234567890";
//    ft_bzero(src, 10);
//    printf ("src: %s!\n",src);
//    return 0;
// }
