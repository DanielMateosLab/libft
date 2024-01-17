/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:51:55 by damateos          #+#    #+#             */
/*   Updated: 2024/01/17 23:05:50 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;

	bytes = count * size;
	ptr = (char *)malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	while (bytes--)
		ptr[bytes] = 0;
	return (ptr);
}
