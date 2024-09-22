/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:56:24 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/22 19:58:25 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  x;

    if (!s)
        return (NULL);  
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s) - start < len)
        len = ft_strlen(s + start);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL); 
    x = 0;
    while (s[x] && x < len)
    {
        str[x] = s[start];
        start++;
        x++;
    }
    str[x] = '\0';
    return (str);
}
