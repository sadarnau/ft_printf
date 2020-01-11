/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:39:05 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/31 18:11:39 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(const char *txt, t_struct *rps, va_list ap)
{
	rps = ft_reinitialize_rps(rps);
	ft_handle_caca(txt, rps, ap);
	if (txt[rps->i] == 'c')
		ft_putchar(va_arg(ap, int), rps);
	else if (txt[rps->i] == 's')
		ft_putstr(va_arg(ap, char*), rps);
	else if (txt[rps->i] == 'p')
		ft_print_addr(va_arg(ap, long unsigned), rps);
	else if (txt[rps->i] == 'd' || txt[rps->i] == 'i')
		ft_print_nbr(va_arg(ap, int), rps);
	else if (txt[rps->i] == 'u')
		ft_print_nbr(va_arg(ap, unsigned int), rps);
	else if (txt[rps->i] == 'x')
		ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef", rps);
	else if (txt[rps->i] == 'X')
		ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF", rps);
	else if (txt[rps->i] == '%')
		ft_putchar('%', rps);
	else if (txt[rps->i])
		ft_putchar(txt[rps->i], rps);
	if (txt[rps->i])
		rps->i++;
}

void	ft_flags(const char *txt, t_struct *rps, int j, va_list ap)
{
	char	*str;
	int		k;

	if ((str = malloc(sizeof(char) * (j - rps->i) + 1)) == 0)
		str = NULL;
	k = 0;
	while (rps->i < j)
	{
		str[k] = txt[rps->i];
		rps->i++;
		k++;
	}
	str[k] = '\0';
	ft_parse_flags(rps, str, ap);
	if (rps->flags == '0')
		rps->fill = '0';
	free(str);
}

void	ft_parse_flags(t_struct *rps, char *str, va_list ap)
{
	int	j;

	j = -1;
	while (str[++j])
	{
		if (str[j] == '-')
			rps->flags = '-';
		else if (str[j] == '0' && rps->flags != '-')
			rps->flags = '0';
		else if (str[j] == '.')
			j = ft_precision(rps, str, ap, j);
		else if ((str[j] >= '1' && str[j] <= '9') || str[j] == '*')
			j = ft_width(rps, str, ap, j);
	}
}

int		ft_precision(t_struct *rps, char *str, va_list ap, int j)
{
	int	nbr;
	int	i;

	j++;
	if (str[j] == '*')
	{
		if ((nbr = va_arg(ap, int)) < 0)
			i = 1;
		rps->precision = nbr;
	}
	else if (str[j] >= '0' && str[j] <= '9')
	{
		rps->precision = ft_atoi(str + j);
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		j--;
	}
	else
	{
		rps->precision = 0;
		j--;
	}
	rps->switch_precision = 1;
	return (j);
}

int		ft_width(t_struct *rps, char *str, va_list ap, int j)
{
	int	nbr;

	if (str[j] == '*')
	{
		if ((nbr = va_arg(ap, int)) < 0)
		{
			nbr *= -1;
			rps->flags = '-';
		}
		rps->width = nbr;
	}
	else
	{
		rps->width = ft_atoi(str + j);
		while (str[j] >= '0' && str[j] <= '9')
		{
			j++;
		}
		j--;
	}
	rps->switch_width = 1;
	return (j);
}
