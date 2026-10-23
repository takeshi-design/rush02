/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 22:15:34 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/10 06:39:31 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d_copy;
	const char	*s_copy;

	d_copy = (char *)dest;
	s_copy = (const char *)src;
	if (dest > src)
	{
		d_copy = d_copy + n;
		s_copy = s_copy + n;
		while (n--)
			*--d_copy = *--s_copy;
	}
	else
	{
		while (n--)
			*d_copy++ = *s_copy++;
	}
	return (dest);
}
