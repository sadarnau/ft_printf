/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:40:03 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/30 17:15:43 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_initialize_rps(t_struct *rps)
{
	rps->flags = '\0';
	rps->fill = ' ';
	rps->switch_width = 0;
	rps->width = 0;
	rps->switch_precision = 0;
	rps->precision = 0;
	rps->count = 0;
	rps->i = 0;
	rps->neg = 0;
	return (rps);
}

t_struct	*ft_reinitialize_rps(t_struct *rps)
{
	rps->flags = '\0';
	rps->fill = ' ';
	rps->switch_width = 0;
	rps->width = 0;
	rps->switch_precision = 0;
	rps->precision = 0;
	rps->neg = 0;
	return (rps);
}
