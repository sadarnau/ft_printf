/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:14:45 by sadarnau          #+#    #+#             */
/*   Updated: 2019/10/31 17:35:31 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ntimes(char c, int n, t_struct *rps)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rps->count += write(1, &c, 1);
		i++;
	}
}

int		ft_len_int(long n)
{
	int		len;

	len = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_hex_len(long unsigned nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

char	*ft_transform_hex(long unsigned nbr, char *hex)
{
	int				i;
	char			*str;

	i = ft_hex_len(nbr);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	if (nbr == 0)
		str[i] = '0';
	while (nbr != 0)
	{
		str[i] = hex[nbr % 16];
		nbr = nbr / 16;
		i--;
	}
	return (str);
}

void	ft_putnbr(long n, t_struct *rps)
{
	char c;
	long nnbr;

	nnbr = n;
	if (nnbr < 0)
	{
		rps->count += write(1, "-", 1);
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
			ft_putnbr(nnbr / 10, rps);
		c = nnbr % 10 + 48;
		rps->count += write(1, &c, 1);
	}
	if (n == 0)
		rps->count += write(1, "0", 1);
}
