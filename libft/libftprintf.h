/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:24:16 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/28 10:17:47 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd_f(int n, int fd, int *num);
void	ft_putnbr_u_fd(unsigned int n, int fd, int *num);
void	ft_putstr_long_fd(unsigned long long l, int fd, int *num);
void	ft_putstr_ui_fd(unsigned int i, int fd, int *num, int is_ul_case);
void	ft_printf_c(int *num, va_list args);
void	ft_printf_s(int *num, va_list args);
void	ft_printf_p(int *num, va_list args);
void	ft_printf_d(int *num, va_list args);
void	ft_printf_i(int *num, va_list args);
void	ft_printf_u(int *num, va_list args);
void	ft_printf_x(int *num, va_list args);
void	ft_printf_xx(int *num, va_list args);
void	ft_printf_pp(int *num);

#endif
