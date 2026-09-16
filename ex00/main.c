/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:10:25 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/09/13 21:56:13 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict *dict)
{
	int	dict_idx;

	if (dict == NULL)
		return ;
	dict_idx = 0;
	while (dict[dict_idx].num != NULL)
	{
		free(dict[dict_idx].num);
		free(dict[dict_idx].str);
		dict_idx++;
	}
	free(dict);
}

int	num_error_in_main(void)
{
	ft_putstr_error("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	int		ret_main;

	dict = NULL;
	ret_main = 0;
	if ((argc != 2 && argc != 3) || (argc == 2 && is_num_valid(argv[1]) == -1)
		|| (argc == 3 && is_num_valid(argv[2]) == -1))
		return (num_error_in_main());
	if (argc == 2)
	{
		dict = read_dict("numbers.dict");
		if (dict == NULL)
			return (1);
		ret_main = put_num(argv[1], dict);
	}
	else if (argc == 3)
	{
		dict = read_dict(argv[1]);
		if (dict == NULL)
			return (1);
		ret_main = put_num(argv[2], dict);
	}
	free_dict(dict);
	return (ret_main);
}
