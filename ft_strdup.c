/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:09:15 by damateos          #+#    #+#             */
/*   Updated: 2024/01/17 23:33:56 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	s2[len] = '\0';
	while (len)
	{
		s2[len] = (char)s1[len];
		len--;
	}
	return (s2);
	// TODO: debug with lldb
}
