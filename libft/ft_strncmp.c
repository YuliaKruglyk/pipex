/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:13:44 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/10 18:47:07 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && i < n - 1 && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

// int	main(void)
// {
// 	char	str1[] = {"424242"};
// 	char	str2[] = {"424242"};

// 	if (ft_strncmp(str1, str2, 2) == 0)
// 		printf("First 2 symbols are identical\n");
// 	else
// 		printf("First 2 symbols are not identical\n");
// 	return (0);
// }
