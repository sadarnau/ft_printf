/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:55:08 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/31 18:20:41 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign *= (str[i++] == '-') ? -1 : 1;
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + str[i++] - 48;
	return (num * sign);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_handle_caca(const char *txt, t_struct *rps, va_list ap)
{
	int	j;

	j = rps->i;
	while ((txt[j] >= '0' && txt[j] <= '9') || txt[j] == ' ' ||
	txt[j] == '.' || txt[j] == '*' || txt[j] == '-')
		j++;
	if (j != rps->i)
		ft_flags(txt, rps, j, ap);
}

void	ft_caca(t_struct *rps, int l, long unsigned p)
{
	if (rps->switch_precision && !(rps->precision) && p)
		rps->count += write(1, " ", 1);
	ft_print_ntimes(' ', rps->width - l - 2, rps);
}
