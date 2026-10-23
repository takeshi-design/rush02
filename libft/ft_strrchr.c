/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:19:30 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/10 08:38:48 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s != '\0')
		s++;
	if ((char) c == '\0')
		return ((char *)s);
	while (s != start)
	{
		s--;
		if ((unsigned char )*s == (unsigned char )c)
			return ((char *)s);
	}
	return (NULL);
}
