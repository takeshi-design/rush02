/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:26:03 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/09/13 21:53:49 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_num_valid(char *str)
{
	int	i;

	if (ft_strlen(str) == 0)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

t_dict	*dict_error(void)
{
	ft_putstr_error("Dict Error\n");
	return (NULL);
}

t_dict	*dict_error_free(char *dict_str)
{
	ft_putstr_error("Dict Error\n");
	free(dict_str);
	return (NULL);
}

t_dict	*dict_error_num_free(char *dict_str, t_dict *dict, int dict_cur_idx)
{
	int	dict_idx;

	ft_putstr_error("Dict Error\n");
	free(dict_str);
	dict_idx = 0;
	while (dict_idx < dict_cur_idx)
	{
		free(dict[dict_idx].num);
		free(dict[dict_idx].str);
		dict_idx++;
	}
	free(dict);
	return (NULL);
}

t_dict	*dict_error_str_free(char *dict_str, t_dict *dict, int dict_cur_idx)
{
	int	dict_idx;

	ft_putstr_error("Dict Error\n");
	free(dict_str);
	dict_idx = 0;
	while (dict_idx < dict_cur_idx)
	{
		free(dict[dict_idx].num);
		free(dict[dict_idx].str);
		dict_idx++;
	}
	free(dict[dict_cur_idx].num);
	free(dict);
	return (NULL);
}
