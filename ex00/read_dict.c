/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:54:42 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 22:42:21 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_value(char *dict_str)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	if (dict_str[idx] == '\n')
	{
		while (dict_str[idx] == '\n')
			idx++;
	}
	while (dict_str[idx])
	{
		if (dict_str[idx] == '\n')
		{
			while (dict_str[idx] == '\n')
				idx++;
		}
		else
		{
			count++;
			while (dict_str[idx] && dict_str[idx] != '\n')
				idx++;
		}
	}
	return (count);
}

int	dict_rule_error(char *str)
{
	int	str_idx;

	str_idx = 0;
	ignore_newline(str, &str_idx);
	while (str[str_idx])
	{
		ignore_space(str, &str_idx);
		if (!(str[str_idx] >= '0' && str[str_idx] <= '9'))
			return (1);
		ignore_number(str, &str_idx);
		ignore_space(str, &str_idx);
		if (str[str_idx] != ':')
			return (1);
		else if (str[str_idx])
			str_idx++;
		ignore_space(str, &str_idx);
		if (str[str_idx] == '\n' || !(str[str_idx] >= ' '
				&& str[str_idx] <= '~'))
			return (1);
		while (str[str_idx] != '\n' && (str[str_idx] >= ' '
				&& str[str_idx] <= '~'))
			str_idx++;
		ignore_newline(str, &str_idx);
	}
	return (0);
}

t_dict	*dict_error_free_dict(t_dict *dict)
{
	int	dict_idx;

	ft_putstr_error("Dict Error\n");
	dict_idx = 0;
	while (dict[dict_idx].num)
	{
		free(dict[dict_idx].num);
		free(dict[dict_idx].str);
		dict_idx++;
	}
	free(dict);
	return (NULL);
}

t_dict	*read_dict(char *argv)
{
	int		fd;
	ssize_t	read_size;
	size_t	total_size;
	char	buf[100];
	t_dict	*dict;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (dict_error());
	total_size = 0;
	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(fd, buf, 100);
		if (read_size == -1)
			return (dict_error());
		total_size += read_size;
	}
	if (close(fd) == -1)
		return (dict_error());
	dict = malloc_dict(argv, total_size);
	if (dict != NULL && have_required_num(dict) == -1)
		return (dict_error_free_dict(dict));
	return (dict);
}
