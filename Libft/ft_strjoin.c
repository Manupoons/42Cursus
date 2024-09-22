/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:59:10 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/22 22:07:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char   *res;
    size_t x;
    size_t y;

    res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!res)
        return (NULL);
    res = (char *)s1;
    x = 0;
    y = ft_strlen(s1);
    while (s2[x])
    {
        res[y + x] = s2[x];
        x++;
    }
    res[x + y] = '\0';
    return(res);
}  