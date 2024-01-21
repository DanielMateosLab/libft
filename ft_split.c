/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:44:51 by damateos          #+#    #+#             */
/*   Updated: 2024/01/21 11:56:18 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			in_word = 1;
			count++;
		}
		if (in_word && *s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**clean_arr(char **arr, size_t len)
{
	while (len--)
	{
		free(arr[len]);
		arr[len] = NULL;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

// 'hola que  tal '
char	**ft_split(char const *s, char c)
{
	size_t		words_count;
	const char	*word_start;
	size_t		word_len;
	char		**arr;
	size_t		arr_i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	word_start = NULL;
	word_len = 0;
	arr_i = 0;
	arr = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[words_count] = NULL;
	while (*s)
	{
		if (!word_start && *s != c)
			word_start = s;
		if (word_start && *s != c)
			word_len++;
		if (word_start && (*s == c || !*(s + 1)))
		{
			if (*s != c)
				word_len++;
			arr[arr_i++] = ft_substr(word_start, 0, word_len);
			if (!arr[arr_i - 1])
				return (clean_arr(arr, arr_i));
			word_start = NULL;
			word_len = 0;
		}
		s++;
	}
	return (arr);
}
