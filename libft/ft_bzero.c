/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 21:40:57 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/12 11:58:23 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c_dest;
	size_t			i;

	c_dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		c_dest[i] = '\0';
		i++;
	}
}
