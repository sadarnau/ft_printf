/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:32:20 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/30 17:16:08 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *txt, ...)
{
	va_list		ap;
	t_struct	*rps;

	if (!(rps = malloc(sizeof(t_struct))))
		return (-1);
	rps = ft_initialize_rps(rps);
	va_start(ap, txt);
	while (txt[rps->i])
	{
		if (txt[rps->i] != '%')
		{
			rps->count += write(1, &txt[rps->i], 1);
			rps->i++;
		}
		else
		{
			rps->i++;
			ft_parse(txt, rps, ap);
		}
	}
	va_end(ap);
	free(rps);
	return (rps->count);
}
