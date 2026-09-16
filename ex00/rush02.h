/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 20:08:10 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 21:56:20 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*num;
	char	*str;
}			t_dict;

int			num_error_in_main(void);
char		*lookup_in_dict(char *num, t_dict *dicts);
int			put_between_digits(char *num, int put_len, t_dict *dicts);
int			put_num_block(char *num, int put_len, t_dict *dicts);
void		put_same_num(char *num, t_dict *dicts);
int			put_num(char *num, t_dict *dicts);
int			is_similar_to_hundred(char *num, t_dict *dicts);
int			put_big_num(int zero_len, t_dict *dicts);
void		ignore_extra_zero(char **num);
int			is_rest_zero(char *num, int put_len);
int			continue_zero(char *num, int put_len);
int			put_num_one_digit(char *num, t_dict *dicts);
int			put_num_two_to_one(char *num, t_dict *dicts);
int			put_num_two_digits(char *num, t_dict *dicts);
int			put_num_three_digits(char *num, t_dict *dicts);
void		free_dict(t_dict *dict);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
void		ft_putstr_error(char *str);
t_dict		*dict_error(void);
t_dict		*dict_error_free(char *dict_str);
int			count_value(char *dict_str);
void		ignore_newline(char *dict_str, int *idx);
void		ignore_space_and_colon(char *dict_str, int *idx);
void		ignore_space(char *dict_str, int *idx);
void		ignore_number(char *dict_str, int *idx);
t_dict		*dict_error_num_free(char *dict_str, t_dict *dict,
				int dict_cur_idx);
t_dict		*dict_error_str_free(char *dict_str, t_dict *dict,
				int dict_cur_idx);
int			dict_rule_error(char *str);
t_dict		*malloc_num(char *dict_str, int *str_idx, int *dict_idx,
				t_dict *dict);
t_dict		*malloc_str(char *dict_str, int *str_idx, int *dict_idx,
				t_dict *dict);
t_dict		*malloc_struct(char *dict_str);
t_dict		*malloc_dict(char *argv, size_t total_size);
int			have_required_num(t_dict *dict);
int			have_one_digit_num(t_dict *dict);
int			have_two_digit_num(t_dict *dict);
int			have_two_digit_num_ex(t_dict *dict);
int			have_over_one_hundred(t_dict *dict);
t_dict		*dict_error_free_dict(t_dict *dict);
t_dict		*read_dict(char *argv);
int			is_num_valid(char *str);

#endif