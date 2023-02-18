/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:31:22 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/05 15:32:22 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_pos_neg(int n)
{
	int	pn;

	pn = 1;
	if (n < 0)
		pn = -1;
	return (pn);
}

char	*ft_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		pn;

	pn = ft_pos_neg(n);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	ft_null(n, str);
	str[len] = '\0';
	while (n)
	{
		str[--len] = (char)((n % 10) * (2 * (n > 0) - 1) + '0');
		n = n / 10;
	}
	len --;
	if (pn < 0)
		str[len] = '-';
	return (str);
}

// int	main()
// {
// 	printf("%s\n", ft_itoa(-2345));
// 	return (0);
// }
