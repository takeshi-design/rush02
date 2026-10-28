/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:24:44 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/27 06:40:02 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*include*/
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*original printf function*/
int		ft_printf(const char *format, ...);

/*utility function*/
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_n(unsigned int n);
char	*sixteen_base(unsigned long n, char *hex_base);

/*judge the specifier*/
void	check_specifier(const char *format, va_list *va_cp, int *count);
int		can_insert_char(char next_c);

/*set each specifier*/
void	put_at_c(va_list *va_copy, int *count);
void	put_at_s(va_list *va_copy, int *count);
void	put_at_d(va_list *va_copy, int *count);
void	put_at_u(va_list *va_copy, int *count);
void	put_at_i(va_list *va_copy, int *count);
void	put_at_x(va_list *va_copy, int *count);
void	put_at_x_big(va_list *va_copy, int *count);
void	put_at_p(va_list *va_copy, int *count);

/*put_str_print*/
int		put_str_printf(const char *format, va_list *va_cp);

/*check error and put char*/
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *str, int *count);
//void	ft_putstr_count_ex(char *str, int *count);
void	ft_putnbr_count(char *str, int *count);

#endif