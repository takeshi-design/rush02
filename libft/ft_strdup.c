/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:12 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/12 12:52:30 by tchijiwa         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*back;
	char	*head;

	back = malloc(sizeof(char) * (ft_strlen(s) + 1));
	head = back;
	if (back == NULL)
		return (NULL);
	while (*s != '\0')
		*back++ = *s++;
	*back = '\0';
	return (head);
}
