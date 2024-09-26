/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:19 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/25 11:06:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*aux;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		aux = f(lst->content);
		node = ft_lstnew(aux);
		if (!node)
		{
<<<<<<< HEAD
			del(aux);
=======
>>>>>>> 4d8c98c183f85e77a7aed8b4a0ad9bc5138ce5c3
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
