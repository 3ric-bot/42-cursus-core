/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy_list;
	t_list	*mapped_block;

	copy_list = NULL;
	while (lst != NULL && f != NULL)
	{
		mapped_block = ft_lstnew(f(lst->content));
		if (mapped_block == NULL)
		{
			ft_lstclear(&copy_list, del);
			return (NULL);
		}
		ft_lstadd_back(&copy_list, mapped_block);
		lst = lst->next;
	}
	return (copy_list);
}
