/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:39:45 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/10 18:35:23 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_memmove (str, s1, ft_strlen(s1));
	ft_memmove (str + ft_strlen(s1), s2, ft_strlen(s2));
	str[len] = '\0';
	return (str);
}

// int main()
// {
// 	char str1[] = "Hello, ";
// 	char str2[] = "World";
// 	printf("%s", ft_strjoin(str1, str2));
// }
