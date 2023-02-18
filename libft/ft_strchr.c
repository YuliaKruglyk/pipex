/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:13:11 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/08 19:23:15 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((s[i] == (char)c))
		return ((char *)s + i);
	return (0);
}

// int	main(void)
// {
//    char	str[11] = "123456769";
//    int	ch = '6';
//    char	*ach;
//    ach = ft_strchr(str, ch);
//    if (ach == NULL)
//       printf ("We didn't find it\n");
//    else
//       printf ("We found it on position - %ld\n", (ach-str+1));
//    return (0);
// }
