/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:42:30 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/08 19:26:22 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// int	main(void)
// {
//    unsigned char	src[15] = "1234567890";
//    char	*sym;
//    printf ("string: %s\n",src); 
//    sym = ft_memchr (src, '4', 10);
//    if (sym != NULL)
//       sym[0]='!';
//    printf ("show the symbol: %s\n",src);
//    return 0;
// }
