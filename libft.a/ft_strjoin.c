/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:02:44 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/12 19:23:28 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*assemble;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	assemble = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (assemble == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		assemble[i++] = *s1++;
	while (*s2)
		assemble[i++] = *s2++;
	assemble[i] = '\0';
	return (assemble);
}
