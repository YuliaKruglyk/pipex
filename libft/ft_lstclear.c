/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:45 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/10 17:54:27 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{	
		temp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

// void	del(void *a)
// {
// 	printf ("removed - %s\n", (char *)a);
// 	return ;
// }
// int	main()
// {
// 	t_list	*lst;
// 	t_list	*lst1;
// 	lst = ft_lstnew("Yulia");
// 	lst -> next = ft_lstnew("Kruhlyk");
// 	lst -> next -> next = ft_lstnew("23");
// 	lst -> next -> next -> next = ft_lstnew("y.o");
// 	ft_lstclear(&(lst -> next), del);
// 	lst1 = lst;
// 	while (lst)
// 	{
// 		printf("%s\n", lst -> content);
// 		lst = lst -> next;
// 	}
// }
