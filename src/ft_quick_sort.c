/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:37:03 by damateos          #+#    #+#             */
/*   Updated: 2024/09/21 15:28:54 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Partitions the array segment and returns the pivot index.
 *
 * @param arr  The array to partition.
 * @param low  The starting index of the segment.
 * @param high The ending index of the segment.
 * @return     The index of the pivot after partitioning.
 */
int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

/**
 * Quick sort recursive function.
 * @param arr  The array to sort.
 * @param low  The starting index of the array segment to sort.
 * @param high The ending index of the array segment to sort.
 */
void	ft_quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_quick_sort(arr, low, pi - 1);
		ft_quick_sort(arr, pi + 1, high);
	}
}

void	ft_reverse_order(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	temp;

	i = low;
	j = high;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}
