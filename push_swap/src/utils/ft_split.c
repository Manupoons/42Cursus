/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:13:15 by mamaratr          #+#    #+#             */
/*   Updated: 2025/01/02 11:36:05 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_count_words(char *s, char c)
{
	size_t	x;
	int		count;

	x = 0;
	count = 0;
	while (s && s[x])
	{
		if (s[x] != c)
		{
			count++;
			while (s[x] != c && s[x])
				x++;
		}
		else
			x++;
	}
	return (count);
}

static char	**do_split(char *s, char c, char **split)
{
	size_t	start;
	size_t	i;
	size_t	j;
	
	start = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[j] = ft_substr(s, start, i - start + 1);
			if (!split[j])
			{
				ft_free_split(split);
				return (NULL);
			}
			j++;
		}
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	split = do_split(s, c, split);
	return (split);
}
/*
char	**ft_split(char *s, char c)
{
	char	**strs;
	size_t	x;
	size_t	len;

	x = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		len = ft_word_len(s, c);
		if (len)
		{
			strs[x] = ft_substr(s, 0, len);
			if (!strs[x])
				return (ft_free(strs, x));
			x++;
		}
		s += len;
	}
	strs[x] = NULL;
	return (strs);
}
*/
