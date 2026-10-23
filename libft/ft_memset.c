/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:24:58 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/11 09:39:51 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char		*c_dest;
	size_t		i;

	c_dest = (char *)s;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c;
		i++;
	}
	return (s);
}
