/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:09:03 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/07 12:12:03 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int							i;
	int							pn;
	unsigned long long			num;
	unsigned long long			prev;

	i = 0;
	pn = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		pn *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		prev = num;
		num = num * 10 + str[i++] - '0';
		if ((prev < 0 && num > 0) || (prev > 0 && num < 0))
			return ((pn == 1) * -1);
	}
	return (num * pn);
}

// int	main(void)
// {
// 	const char str[] = "-3 45f";
// 	int res;
// 	int lib;
// 	res = ft_atoi(str);
// 	lib = atoi(str);
// 	printf("num: %d\n", res);
// 	printf("lib: %d\n", lib);
// 	return 0;
// }
