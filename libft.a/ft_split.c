/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:30:31 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/15 19:16:10 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strlen_sp(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		num_words;
	char	**str_ar;

	if (s == NULL)
		return (NULL);
	len = strlen_sp(*s, c);
	str_ar = malloc(sizeof(char *) * (len + 1));
	if (str_ar == NULL)
		return (NULL);
	str_ar[len] = NULL;
	num_words = 0;
	while (num_words < len)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			str_ar[num_words] = make_word(s, c);
			s++;
		}
		while (*s && !is_sep(*s, c))
			s++;
	}
	return (str_ar);
}
