/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:36:01 by hamzabillah       #+#    #+#             */
/*   Updated: 2024/11/25 10:02:16 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_format(char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (sp == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (sp == 'd' || sp == 'i')
		count += printdigit((long)va_arg(ap, int), 10);
	else if (sp == 'x')
		count += printdigit((long)va_arg(ap, unsigned int), 16);
	else if (sp == 'X')
		count += printdigit_upper((unsigned long)va_arg(ap, unsigned int), 16);
	else if (sp == 'p')
		count += print_pointer(va_arg(ap, unsigned long));
	else if (sp == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else
		count += write(1, &sp, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*(format), ap);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/*int main (void)
{
	ft_printf("hhh %p\n "   "  %s", 0, "hamza");
	printf("%p\n", 0);
}*/
