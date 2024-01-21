/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:23:06 by damateos          #+#    #+#             */
/*   Updated: 2024/01/21 18:24:17 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*res;

	res = malloc(sizeof(char) * ((size = get_size(n)) + 1));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	if (n == -2147483648)
	{
		res[size--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[size--] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (res);
}
