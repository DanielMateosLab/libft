/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:05:27 by default           #+#    #+#             */
/*   Updated: 2024/10/31 21:37:38 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	node = *lst;
	if (node->next)
		ft_lstclear(&(node->next), del);
	if (del)
		del(node->content);
	free(node);
	*lst = NULL;
}
