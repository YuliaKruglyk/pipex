/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:11 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/08 19:05:13 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (start <= ft_strlen(s) && i < len)
	{
		str[i] = s[i + start];
		i ++;
	}
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	char str1[] = "r";
// 	printf("%s", ft_substr(str1, 1, 1));
// }
