/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:48 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/24 09:40:04 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
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

static char	**ft_free(char **strs, int x)
{
	while (x > 0)
		free(strs[x--]);
	free(strs);
	return (NULL);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	x;
	size_t	len;

	x = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (ft_free(strs, 0));
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
