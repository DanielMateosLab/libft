/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:22:48 by damateos          #+#    #+#             */
/*   Updated: 2024/08/24 20:19:22 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_array_copy_n(char **arr, size_t n)
{
	char	**new_arr;
	size_t	i;

	if (!arr)
		return (NULL);
	new_arr = (char **)ft_calloc(n + 1, sizeof(char *));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < n && arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
			return (str_array_clear(new_arr));
		i++;
	}
	return (new_arr);
}
