/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:54:22 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/31 18:20:30 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_struct *rps)
{
	if (rps->switch_width == 0 || rps->width == 1)
	{
		rps->count += write(1, &c, 1);
	}
	else
	{
		if (rps->flags == '-')
		{
			rps->count += write(1, &c, 1);
			ft_print_ntimes(rps->fill, rps->width - 1, rps);
		}
		else
		{
			ft_print_ntimes(rps->fill, rps->width - 1, rps);
			rps->count += write(1, &c, 1);
		}
	}
}

void	ft_putstr(char *s, t_struct *rps)
{
	int l;

	if (s == NULL)
		s = "(null)";
	l = ft_strlen(s);
	if (rps->switch_precision && rps->precision < l && rps->precision >= 0)
		l = rps->precision;
	if (rps->flags == '-' || (rps->switch_width && rps->width <= l))
	{
		if (rps->switch_precision && rps->precision < l && rps->precision >= 0)
		{
			l = write(1, s, rps->precision);
			rps->count += l;
		}
		else
			rps->count += write(1, s, l);
		if (rps->width > l)
			ft_print_ntimes(' ', rps->width - l, rps);
	}
	else
		ft_putstr_bis(s, rps, l);
}

void	ft_print_nbr(long nbr, t_struct *rps)
{
	long	l;
	int		neg;

	neg = (nbr < 0) ? 1 : 0;
	if (neg)
		nbr *= -1;
	l = ft_len_int(nbr);
	if (rps->flags == '-' || (rps->switch_width && rps->width <= l))
	{
		if (neg)
			rps->count += write(1, "-", 1);
		if (rps->switch_precision && rps->precision > l)
			ft_print_ntimes('0', rps->precision - l, rps);
		ft_putnbr(nbr, rps);
		if (rps->width > l && rps->precision <= l)
			ft_print_ntimes(' ', rps->width - l - neg, rps);
		else if (rps->width > l && rps->precision > l)
			ft_print_ntimes(' ', rps->width - rps->precision - neg, rps);
	}
	else
		ft_print_nbr_bis(nbr, rps, l, neg);
}

void	ft_print_hex(long unsigned nbr, char *hex, t_struct *rps)
{
	long	l;
	char	*str;

	l = ft_hex_len(nbr);
	if (rps->flags == '-' || (rps->switch_width && rps->width <= l))
	{
		if (rps->switch_precision && rps->precision > l)
			ft_print_ntimes('0', rps->precision - l, rps);
		str = ft_transform_hex(nbr, hex);
		rps->count += write(1, str, l);
		free(str);
		if (rps->width > l && rps->precision <= l)
			ft_print_ntimes(' ', rps->width - l, rps);
		else if (rps->width > l && rps->precision > l)
			ft_print_ntimes(' ', rps->width - rps->precision, rps);
	}
	else
		ft_print_hex_bis(nbr, hex, rps, l);
}

void	ft_print_addr(long unsigned p, t_struct *rps)
{
	int		l;
	char	*str;

	str = ft_transform_hex(p, "0123456789abcdef");
	l = ft_hex_len(p);
	if (rps->switch_precision && !rps->precision && !p)
		l = 0;
	if (rps->flags == '-' || (rps->switch_width && rps->width <= l + 2))
	{
		rps->count += write(1, "0x", 2);
		if (rps->switch_precision && rps->precision > l)
			ft_print_ntimes('0', rps->precision - l, rps);
		if ((rps->switch_precision && rps->precision) || !rps->switch_precision)
			rps->count += write(1, str, l);
		if (rps->width > l + 2 && rps->precision < l + 2)
			ft_caca(rps, l, p);
		else if (rps->width > l + 2 && rps->precision > l)
			ft_print_ntimes(' ', rps->width - rps->precision - 2, rps);
	}
	else
		ft_print_addr_bis(p, rps, l, str);
	free(str);
}
