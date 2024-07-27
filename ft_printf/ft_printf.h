/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:04:56 by badriano          #+#    #+#             */
/*   Updated: 2024/07/26 09:07:49 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int ft_putchar_len(char c, int current_len);
int ft_print_num(int num, int current_len);
int num_len(int num, int current_len);
int ft_putstr(char *str, int current_len);
int ft_printf(const char *str, ...);
#include <sys/types.h>

#endif
