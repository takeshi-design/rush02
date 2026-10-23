/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:12:43 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/12 19:52:35 by tchijiwa         ###   ########.fr       */
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

char	*ma_cpy_str(size_t length, unsigned int start, char const *s)
{
	char	*head;
	char	*h;

	head = malloc(sizeof(char) * (length - start + 1));
	if (head == NULL)
		return (NULL);
	h = head;
	while (s[start] != '\0')
		*head++ = s[start++];
	*head = '\0';
	return (h);
}

char	*ma_cpy_max(size_t len, unsigned int start, char const *s)
{
	char	*h;
	size_t	i;

	h = malloc(sizeof(char) * (len + 1));
	if (h == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		h[i++] = s[start++];
	h[i] = '\0';
	return (h);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	length;

	sub_str = NULL;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start > (unsigned int)ft_strlen(s))
	{
		sub_str = malloc(1);
		if (sub_str == NULL)
			return (NULL);
		*sub_str = '\0';
	}
	else if (length - start < len)
		sub_str = ma_cpy_str(length, start, s);
	else if (length - start >= len)
		sub_str = ma_cpy_max(len, start, s);
	return (sub_str);
}
