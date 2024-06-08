/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:04:00 by damateos          #+#    #+#             */
/*   Updated: 2024/06/08 19:27:06 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Typical max size of unsigned int: 2^32 4.294.967.295 or 4mb
// Algo of my namesake djb2 (Daniel J. Bernstein)

unsigned int	ft_hash(const char *string)
{
	const unsigned char	*u_str;
	unsigned int		hash;

	hash = 5381;
	u_str = (const unsigned char *)string;
	while (*u_str)
		hash = hash * 33 + ft_tolower(*u_str++);
	return (hash);
}
