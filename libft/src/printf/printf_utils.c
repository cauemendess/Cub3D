/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:04:26 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/16 21:18:37 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	if (str == NULL)
		return (ft_putstr("(null)"));
	length = 0;
	while (str[length] != '\0')
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}

int	ft_putptr(unsigned long nb, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (nb == 0)
		return (ft_putstr("(nil)"));
	if (nb >= (unsigned long)base_length)
		length += ft_putptr((nb / base_length), base);
	else
		length += ft_putstr("0x");
	length += ft_putchar(base[nb % base_length]);
	return (length);
}

int	ft_putnbr_base(long int nb, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (nb < 0)
	{
		length += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= base_length)
		length += ft_putnbr_base((nb / base_length), base);
	length += ft_putchar(base[nb % base_length]);
	return (length);
}
