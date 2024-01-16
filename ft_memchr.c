/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:09:01 by damateos          #+#    #+#             */
/*   Updated: 2024/01/16 22:27:46 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int _c, size_t n)
{
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *)s;
	c = (unsigned char)_c;
	while (*str != c && n--)
		str++;
	if (n && *str == c)
		return ((void *)str);
	return (0);
}
