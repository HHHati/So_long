/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:24:34 by bade-lee          #+#    #+#             */
/*   Updated: 2022/03/13 13:44:47 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

//          ----------========== {    LIB FT    } ==========----------

char	*ft_itoa(long long int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

//          ----------========== {     FCTS     } ==========----------

int		ft_printf(const char *param, ...);
int		param_c(int *counter, va_list params);
int		param_s(int *counter, va_list params);
int		param_p(int *counter, va_list params);
int		param_d(int *counter, va_list params);
int		param_i(int *counter, va_list params);
int		param_u(int *counter, va_list params);
int		param_xlow(int *counter, va_list params);
int		param_xup(int *counter, va_list params);
int		param_prc(int *counter);

#endif