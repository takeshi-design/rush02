/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_required_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:14:31 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 21:21:40 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	have_required_num(t_dict *dict)
{
	if (have_one_digit_num(dict) == -1)
		return (-1);
	if (have_two_digit_num(dict) == -1)
		return (-1);
	if (lookup_in_dict("100", dict) == NULL)
		return (-1);
	if (have_over_one_hundred(dict) == -1)
		return (-1);
	return (0);
}

int	have_one_digit_num(t_dict *dict)
{
	if (lookup_in_dict("0", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1", dict) == NULL)
		return (-1);
	if (lookup_in_dict("2", dict) == NULL)
		return (-1);
	if (lookup_in_dict("3", dict) == NULL)
		return (-1);
	if (lookup_in_dict("4", dict) == NULL)
		return (-1);
	if (lookup_in_dict("5", dict) == NULL)
		return (-1);
	if (lookup_in_dict("6", dict) == NULL)
		return (-1);
	if (lookup_in_dict("7", dict) == NULL)
		return (-1);
	if (lookup_in_dict("8", dict) == NULL)
		return (-1);
	if (lookup_in_dict("9", dict) == NULL)
		return (-1);
	return (0);
}

int	have_two_digit_num(t_dict *dict)
{
	if (lookup_in_dict("10", dict) == NULL)
		return (-1);
	if (lookup_in_dict("11", dict) == NULL)
		return (-1);
	if (lookup_in_dict("12", dict) == NULL)
		return (-1);
	if (lookup_in_dict("13", dict) == NULL)
		return (-1);
	if (lookup_in_dict("14", dict) == NULL)
		return (-1);
	if (lookup_in_dict("15", dict) == NULL)
		return (-1);
	if (lookup_in_dict("16", dict) == NULL)
		return (-1);
	if (lookup_in_dict("17", dict) == NULL)
		return (-1);
	if (lookup_in_dict("18", dict) == NULL)
		return (-1);
	if (lookup_in_dict("19", dict) == NULL)
		return (-1);
	if (have_two_digit_num_ex(dict) == -1)
		return (-1);
	return (0);
}

int	have_two_digit_num_ex(t_dict *dict)
{
	if (lookup_in_dict("20", dict) == NULL)
		return (-1);
	if (lookup_in_dict("30", dict) == NULL)
		return (-1);
	if (lookup_in_dict("40", dict) == NULL)
		return (-1);
	if (lookup_in_dict("50", dict) == NULL)
		return (-1);
	if (lookup_in_dict("60", dict) == NULL)
		return (-1);
	if (lookup_in_dict("70", dict) == NULL)
		return (-1);
	if (lookup_in_dict("80", dict) == NULL)
		return (-1);
	if (lookup_in_dict("90", dict) == NULL)
		return (-1);
	return (0);
}

int	have_over_one_hundred(t_dict *dict)
{
	if (lookup_in_dict("1000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000000000000000", dict) == NULL)
		return (-1);
	if (lookup_in_dict("1000000000000000000000000000000000000", dict) == NULL)
		return (-1);
	return (0);
}
