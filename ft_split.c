/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 17:49:11 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/06/02 14:57:28 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(char const*s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			words++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		i++;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c, int pos)
{
	int	word_len;

	word_len = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		pos++;
		word_len++;
	}
	return (word_len);
}

char	**ft_make_array(char const *s, char c, int word_count, char **split_arr)
{
	int	pos;
	int	array_idx;
	int	num_of_char;

	pos = 0;
	array_idx = 0;
	num_of_char = 0;
	while (array_idx < word_count)
	{
		while (s[pos] == c)
			pos++;
		num_of_char = ft_word_len(s, c, pos);
		split_arr[array_idx] = (char *)ft_calloc(num_of_char + 1, sizeof(char));
		if (!split_arr[array_idx])
			return (NULL);
		ft_strlcpy(split_arr[array_idx], &s[pos], num_of_char + 1);
		pos += num_of_char;
		array_idx++;
	}
	return (split_arr);
}

static void	ft_free_array(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split_arr;

	if (s == NULL)
		return (NULL);
	words = ft_count_word(s, c);
	split_arr = ft_calloc(words + 1, sizeof(char *));
	if (!split_arr)
		return (NULL);
	if (words == 0)
		return (split_arr);
	if (!ft_make_array(s, c, words, split_arr))
	{
		ft_free_array(split_arr);
		return (NULL);
	}
	return (split_arr);
}
