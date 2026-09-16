/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:03:09 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 21:06:58 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ignore_newline(char *dict_str, int *idx)
{
	while (dict_str[*idx] && dict_str[*idx] == '\n')
		(*idx)++;
}

void	ignore_space_and_colon(char *dict_str, int *idx)
{
	while (dict_str[*idx] && dict_str[*idx] == ' ')
		(*idx)++;
	if (dict_str[*idx] && dict_str[*idx] == ':')
		(*idx)++;
	while (dict_str[*idx] && dict_str[*idx] == ' ')
		(*idx)++;
}

void	ignore_space(char *dict_str, int *idx)
{
	while (dict_str[*idx] && dict_str[*idx] == ' ')
		(*idx)++;
}

void	ignore_number(char *dict_str, int *idx)
{
	while (dict_str[*idx] && dict_str[*idx] >= '0' && dict_str[*idx] <= '9')
		(*idx)++;
}
