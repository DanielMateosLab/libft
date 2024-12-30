/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:15:12 by damateos          #+#    #+#             */
/*   Updated: 2024/12/30 18:30:40 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_int_arr_copy(int *arr, size_t len)
{
	int	*copy;
	size_t	i;

	copy = (int *)ft_calloc(len, sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	ft_int_arr_print(int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_int_arr_reverse(int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		ft_swap(&arr[i], &arr[len - i - 1]);
		i++;
	}
}
