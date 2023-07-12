/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:52:33 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/12 14:51:07 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# ifdef __APPLE__
#  define NULLSTRING "(null)"
#  define NULLPOINTER "0x0"
# else
#  define NULLSTRING "(null)"
#  define NULLPOINTER "(nil)"
# endif
# define ESA "0123456789abcdef"
# define UPPERESA "0123456789ABCDEF"

int	ft_print_memory(unsigned long nb);
int	handleneg(int val, int base);
int	ft_putnbr_base(int n, int b);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_unsigned(unsigned int nb, unsigned int bs, char *base);
int	ft_printf(const char *format, ...);
int	handlevalue(char c, va_list args);

#endif
