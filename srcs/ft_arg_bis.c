/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:40:14 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/31 18:17:49 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_bis(char *s, t_struct *rps, int l)
{
	if (rps->width > l && rps->switch_precision && rps->precision < l &&
		rps->precision >= 0)
		ft_print_ntimes(rps->fill, rps->width - rps->precision, rps);
	else if (rps->width > l)
		ft_print_ntimes(rps->fill, rps->width - l, rps);
	if (rps->switch_precision && rps->precision < l && rps->precision >= 0)
	{
		l = write(1, s, rps->precision);
		rps->count += l;
	}
	else
		rps->count += write(1, s, l);
}

void	ft_print_nbr_bis(long nbr, t_struct *rps, int l, int neg)
{
	if (rps->width > l && rps->switch_precision && rps->precision < 0)
		ft_print_ntimes('0', rps->width - l - neg, rps);
	else if (rps->width > l && rps->switch_precision == 0 && rps->flags != '0')
		ft_print_ntimes(' ', rps->width - l - neg, rps);
	else if (rps->width > l && rps->precision > l)
		ft_print_ntimes(' ', rps->width - rps->precision - neg, rps);
	else if (!nbr && rps->switch_precision && !rps->precision)
		ft_print_ntimes(' ', rps->width, rps);
	else if (nbr && rps->switch_precision)
		ft_print_ntimes(' ', rps->width - l - neg, rps);
	if (neg)
		rps->count += write(1, "-", 1);
	if (rps->precision > l)
		ft_print_ntimes('0', rps->precision - l, rps);
	else if (rps->flags == '0' && !rps->switch_precision)
		ft_print_ntimes('0', rps->width - l - neg, rps);
	if (!nbr && rps->switch_precision && !rps->precision)
		neg = 0;
	else
		ft_putnbr(nbr, rps);
}

void	ft_print_hex_bis(long unsigned nbr, char *hex, t_struct *rps, int l)
{
	char	*str;

	str = ft_transform_hex(nbr, hex);
	if (rps->width > l && rps->precision <= l && rps->flags != '0')
		ft_print_ntimes(' ', rps->width - l, rps);
	else if (rps->width > l && rps->precision > l)
		ft_print_ntimes(' ', rps->width - rps->precision, rps);
	if (rps->precision > l)
		ft_print_ntimes('0', rps->precision - l, rps);
	else if (rps->flags == '0' && rps->switch_precision)
		ft_print_ntimes(' ', rps->width - l, rps);
	else if (rps->flags == '0' && !rps->switch_precision)
		ft_print_ntimes('0', rps->width - l, rps);
	if (!nbr && rps->switch_precision && !rps->precision)
		l = 0;
	else
		rps->count += write(1, str, l);
	if (rps->switch_width && rps->switch_precision && !rps->precision && !nbr)
		ft_print_ntimes(' ', 1, rps);
	free(str);
}

void	ft_print_addr_bis(long unsigned p, t_struct *rps, int l, char *str)
{
	if (rps->width > l + 2 && rps->flags != '0')
		ft_print_ntimes(' ', rps->width - l - 2, rps);
	else if (rps->width > l + 2 && rps->precision > l)
		ft_print_ntimes(' ', rps->width - rps->precision - 2, rps);
	else if (rps->width > l + 2 && rps->switch_precision && !rps->precision)
		ft_print_ntimes(' ', rps->width - l - 2, rps);
	rps->count += write(1, "0x", 2);
	if (rps->precision > l)
		ft_print_ntimes('0', rps->precision - l, rps);
	else if (!p && rps->switch_precision && !rps->precision)
		p = 0;
	else if (rps->flags == '0')
		ft_print_ntimes('0', rps->width - 2 - l, rps);
	rps->count += write(1, str, l);
}
