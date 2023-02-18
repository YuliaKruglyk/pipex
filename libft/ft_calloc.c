/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:03 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/08 19:42:54 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int	main(void)
// {
// 	int	*ptr;
// 	ptr = (int*)ft_calloc(10, sizeof(int));
// 	if (ptr == NULL)
// 		printf("Memory not allocated \n");
// 	else 
// 		printf("Memory allocated successfully \n");
// 	free(ptr);
// 	return (0);
// }
