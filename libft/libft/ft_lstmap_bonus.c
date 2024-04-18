/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:20:30 by sruff             #+#    #+#             */
/*   Updated: 2023/11/09 16:33:38 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*begin;
	void	*ptr;

	begin = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			del(ptr);
			ft_lstclear(&new_node, del);
		}
		ft_lstadd_back(&begin, new_node);
		lst = lst->next;
	}
	ft_lstadd_back(&begin, NULL);
	return (begin);
}

//void	*d(void *c)
//{
//	free(c);
//}

//int main(void)
//{

//	ft_lstmap(lst, f(c), d())

//}