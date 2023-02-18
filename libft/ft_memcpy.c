/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:18:39 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/10 17:54:00 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	size_t		i;
	char		*dest;
	const char	*sour;

	i = 0;
	dest = dst;
	sour = src;
	if (dest == sour)
		return (dest);
	while (n > 0)
	{
		*dest = *sour;
		dest++;
		sour++;
		n--;
	}
	return (dst);
}

// int	main(void)
// {
// 	const char src[10] = "123456";
// 	char dst[10] = "";
// 	ft_memcpy(dst, src, 6);
// 	printf("dst: %s\n", dst);
// 	return (0);
// }
