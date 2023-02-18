/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:05:16 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/01 16:55:41 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	size_t			i;
	unsigned char	*tem;

	i = 0;
	tem = (unsigned char *)b;
	while (len > i)
	{
		tem[i] = c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
//    unsigned char src[15]="1234567890";
//    ft_memset (src, '1', 10);
//    printf ("src: %s\n",src);
//    return (0);
// }
