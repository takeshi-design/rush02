/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 00:44:17 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/10 03:50:31 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	origin;
	size_t	cpy;

	origin = 0;
	while (src[origin])
		origin++;
	if (size != 0)
	{
		cpy = 0;
		while (cpy < size - 1 && src[cpy] != '\0')
		{
			dst[cpy] = src[cpy];
			cpy++;
		}
		dst[cpy] = '\0';
	}
	return (origin);
}
