/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 05:58:16 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/12 11:48:09 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cpy;

	s_cpy = (const unsigned char *)s;
	while (n--)
	{
		if (*s_cpy == (unsigned char) c)
			return ((void *)s_cpy);
		s_cpy++;
	}
	return (NULL);
}
