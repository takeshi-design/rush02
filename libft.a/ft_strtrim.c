/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:23:51 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/15 13:40:09 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_c(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	strlen_a(char const *s1, char const *set)
{
	int	count;
	int	i;

	count = 0;
	while (*s1++)
	{
		i = 0;
		if (find_c(*s1, set))
			count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*remove_str;
	char	*head;

	if (s1 == NULL || set == NULL)
		return (NULL);
	remove_str = malloc(sizeof(char) * strlen_a(s1, set));
	head = remove_str;
	if (remove_str == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		if (!(find_c(*s1, set)))
			*remove_str = *s1;
		s1++;
	}
	*remove_str = '\0';
	return (head);
}
