/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:44:41 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/25 10:57:30 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

<<<<<<< HEAD
	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		del(node->content);
=======
	while (*lst)
	{
		node = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
>>>>>>> 4d8c98c183f85e77a7aed8b4a0ad9bc5138ce5c3
		free(node);
	}
}