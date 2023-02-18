/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:51:37 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/10 18:45:33 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	func_up(unsigned int i, char str)
// {	
// 	printf("i%d - %c\n", i , str);
//     return str - 32;
// }
// int main()
// {
//     char    str1[10] = "hello";
//     char    *str2;
// 	printf("The inner - %s\n", str1);
//     str2 = ft_strmapi(str1, func_up);
//     printf("The result - %s\n", str2);
//     return 0;
// }
