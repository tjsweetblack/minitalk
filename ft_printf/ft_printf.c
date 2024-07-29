/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:30:53 by badriano          #+#    #+#             */
/*   Updated: 2024/07/29 13:31:13 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_specifier(char specifier, va_list args, int current_len)
{
	int	len;

	len = 0;
	if (specifier == 'c')
	{
		len = ft_putchar_len(va_arg(args, int), current_len);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		len = ft_print_num(va_arg(args, int), current_len);
	}
	else if (specifier == 's')
	{
		len = ft_putstr(va_arg(args, char *), current_len);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = process_specifier(str[i], args, len);
		}
		else
		{
			len = ft_putchar_len(str[i], len);
		}
		i++;
	}
	va_end(args);
	return (len);
}
