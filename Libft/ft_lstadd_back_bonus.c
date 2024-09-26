/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:00 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/25 10:45:43 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
<<<<<<< HEAD
	t_list	*node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
=======
	if (*lst)
		(ft_lstlast(*lst))->next = new;
	else
>>>>>>> 4d8c98c183f85e77a7aed8b4a0ad9bc5138ce5c3
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}
