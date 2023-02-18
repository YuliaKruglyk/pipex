/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:13:25 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/09 19:51:11 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

// void	func_up(unsigned int i, char *str)
// {	
// 	printf("i%d - %s\n", i, str);
// }
// int main(void)
// {
//     char    str1[10] = "hello.";
// 	printf("The inner - %s\n", str1);
//     ft_striteri(str1, func_up);
//     printf("The result - %s\n", str1);
//     return 0;
// }
