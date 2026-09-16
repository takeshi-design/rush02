/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:27:26 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 21:48:08 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*malloc_num(char *dict_str, int *str_idx, int *dict_idx, t_dict *dict)
{
	int		tmp_idx;
	char	*tmp_str;

	tmp_idx = 0;
	while (dict_str[(*str_idx) + tmp_idx] >= '0' && dict_str[(*str_idx)
			+ tmp_idx] <= '9')
		tmp_idx++;
	tmp_str = malloc(sizeof(char) * (tmp_idx + 1));
	if (tmp_str == NULL)
		return (dict_error_num_free(dict_str, dict, *dict_idx));
	dict[*dict_idx].num = tmp_str;
	ft_strncpy(dict[*dict_idx].num, &dict_str[*str_idx], tmp_idx);
	dict[*dict_idx].num[tmp_idx] = '\0';
	(*str_idx) += tmp_idx;
	return (dict);
}

t_dict	*malloc_str(char *dict_str, int *str_idx, int *dict_idx, t_dict *dict)
{
	int		tmp_idx;
	char	*tmp_str;
	int		space_len;

	tmp_idx = 0;
	while ((dict_str[*str_idx + tmp_idx] >= ' ' && dict_str[*str_idx
				+ tmp_idx] <= '~') && dict_str[(*str_idx) + tmp_idx] != '\n')
		tmp_idx++;
	space_len = 0;
	while (dict_str[(*str_idx) + tmp_idx - space_len - 1] == ' ')
		space_len++;
	tmp_str = malloc(sizeof(char) * (tmp_idx - space_len + 1));
	if (tmp_str == NULL)
		return (dict_error_str_free(dict_str, dict, *dict_idx));
	dict[*dict_idx].str = tmp_str;
	ft_strncpy(dict[*dict_idx].str, &dict_str[*str_idx], tmp_idx - space_len);
	dict[*dict_idx].str[tmp_idx - space_len] = '\0';
	(*str_idx) += tmp_idx;
	return (dict);
}

t_dict	*malloc_struct(char *dict_str)
{
	t_dict	*dict;
	int		dict_idx;
	int		str_idx;

	dict = malloc(sizeof(t_dict) * (count_value(dict_str) + 1));
	if (dict == NULL)
		return (dict_error_free(dict_str));
	dict_idx = 0;
	str_idx = 0;
	while (dict_idx < count_value(dict_str))
	{
		ignore_newline(dict_str, &str_idx);
		ignore_space(dict_str, &str_idx);
		if (malloc_num(dict_str, &str_idx, &dict_idx, dict) == NULL)
			return (NULL);
		ignore_space_and_colon(dict_str, &str_idx);
		if (malloc_str(dict_str, &str_idx, &dict_idx, dict) == NULL)
			return (NULL);
		dict_idx++;
	}
	dict[dict_idx].num = NULL;
	dict[dict_idx].str = NULL;
	free(dict_str);
	return (dict);
}

t_dict	*malloc_dict(char *argv, size_t total_size)
{
	int		fd;
	char	*dict_str;
	ssize_t	read_size;

	dict_str = malloc(sizeof(char) * (total_size + 1));
	if (dict_str == NULL)
		return (dict_error());
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (dict_error_free(dict_str));
	read_size = read(fd, dict_str, total_size);
	if (read_size == -1)
		return (dict_error_free(dict_str));
	dict_str[total_size] = '\0';
	if (close(fd) == -1)
		return (dict_error_free(dict_str));
	if (dict_rule_error(dict_str))
		return (dict_error_free(dict_str));
	return (malloc_struct(dict_str));
}
