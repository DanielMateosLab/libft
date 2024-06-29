/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:04:00 by damateos          #+#    #+#             */
/*   Updated: 2024/06/29 20:23:22 by damateos         ###   ########.fr       */
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

t_hashmap	*ft_hm_create(size_t size, void (*del)(void *))
{
	t_hashmap	*hm;

	hm = (t_hashmap *)malloc(sizeof(t_hashmap));
	if (!hm)
		return (NULL);
	hm->array = ft_calloc(size, 1);
	if (!hm->array)
		return (ft_free((void **)hm));
	hm->size = size;
	hm->del = del;
	return (hm);
}

void	ft_hm_remove(t_hashmap *hm)
{
	size_t		i;
	t_hm_node	*node;
	t_hm_node	*temp;

	i = 0;
	while (i < hm->size)
	{
		node = hm->array[i];
		while (node)
		{
			temp = node->next;
			node = temp->next;
			ft_free((void **)temp->key);
			if (hm->del)
				hm->del(temp->value);
			ft_free((void **)temp->value);
			ft_free((void **)temp);
		}
		i++;
	}
	ft_free((void **)hm->array);
	ft_free((void **)hm);
}
