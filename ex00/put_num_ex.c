/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:31:42 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 20:19:25 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_similar_to_hundred(char *num, t_dict *dicts)
{
	int	num_idx;

	if (ft_strlen(num) <= 2)
		return (0);
	if (num[0] != '1')
		return (0);
	num_idx = 1;
	while (num[num_idx])
	{
		if (num[num_idx] != '0')
			return (0);
		num_idx++;
	}
	if (lookup_in_dict(num, dicts) == NULL)
		return (0);
	return (1);
}

int	put_big_num(int zero_len, t_dict *dicts)
{
	char	*str;
	int		str_idx;

	str = malloc(sizeof(char) * (zero_len + 2));
	if (str == NULL)
		return (-1);
	str[0] = '1';
	str_idx = 1;
	while (zero_len)
	{
		str[str_idx] = '0';
		str_idx++;
		zero_len--;
	}
	str[str_idx] = '\0';
	if (lookup_in_dict(str, dicts) == NULL)
	{
		free(str);
		return (-1);
	}
	ft_putstr(lookup_in_dict(str, dicts));
	free(str);
	return (0);
}

int	is_rest_zero(char *num, int put_len)
{
	int	num_idx;

	num_idx = put_len;
	while (num[num_idx])
	{
		if (num[num_idx] != '0')
			return (0);
		num_idx++;
	}
	return (1);
}

void	ignore_extra_zero(char **num)
{
	int	num_idx;

	num_idx = 0;
	while ((*num)[num_idx] == '0')
		num_idx++;
	if (num_idx == ft_strlen(*num))
		(*num) = &((*num)[num_idx - 1]);
	else
		(*num) = &((*num)[num_idx]);
}

int	continue_zero(char *num, int put_len)
{
	int	num_idx;

	num_idx = put_len;
	while (num_idx <= ft_strlen(num) - 3)
	{
		if (num[num_idx] != '0')
			return (0);
		num_idx++;
	}
	return (1);
}
