/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:10:55 by damateos          #+#    #+#             */
/*   Updated: 2023/12/02 20:30:30 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// We have to avoid this
// aabb___ copy 4 chars from 1 to 2:
// 1 2  ^: end of inserted text
// aaaaaa_ Unintented: result should be aaaabb
// Copying backwards we solve this
// if src is before A, copy backwards.
// otherwise, copy forwards.
void	*memmove(void *dst, const void *src, size_t len)
{
	
}
