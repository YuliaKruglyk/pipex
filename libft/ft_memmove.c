/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:13:22 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/04 20:46:36 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sour;

	dest = (char *)dst;
	sour = (const char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len --)
			dest[len] = sour[len];
		return (dst);
	}
	while (len --)
			*dest++ = *sour++;
	return (dst);
}

// int	main(void)
// {
// 	char src[10] = "1234567890";
// 	printf("src1: %s\n", src);
// 	ft_memmove(&src[5], &src[3], 4);
// 	printf ("src2: %s\n", src);
// 	return (0);
// }
