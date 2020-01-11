/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:39:49 by sam               #+#    #+#             */
/*   Updated: 2019/10/31 18:22:00 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_struct
{
	char	flags;
	char	fill;
	int		switch_width;
	int		width;
	int		switch_precision;
	int		precision;
	int		count;
	int		i;
	int		neg;
}				t_struct;

void			ft_caca(t_struct *rps, int l, long unsigned p);
void			ft_handle_caca(const char *txt, t_struct *rps, va_list ap);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			ft_print_addr_bis(long unsigned p, t_struct *rps,
				int l, char *str);
void			ft_print_hex_bis(long unsigned nbr, char *hex,
				t_struct *rps, int l);
void			ft_print_nbr_bis(long nbr, t_struct *rps, int l, int neg);
void			ft_putstr_bis(char *s, t_struct *rps, int l);
int				ft_precision(t_struct *rps, char *str, va_list ap, int j);
int				ft_width(t_struct *rps, char *str, va_list ap, int j);
void			ft_handle_null(t_struct *rps);
void			ft_putnbr(long n, t_struct *rps);
int				ft_hex_len(long unsigned nbr);
char			*ft_transform_hex(long unsigned nbr, char *hex);
int				ft_len_int(long n);
void			ft_print_ntimes(char c, int n, t_struct *rps);
char			*ft_num_precision(char *str, t_struct *rps);
void			ft_fill(char *s, int n, char to_fill);
void			ft_print_nbr(long nbr, t_struct *rps);
t_struct		*ft_reinitialize_rps(t_struct *rps);
void			ft_parse(const char *txt, t_struct *rps, va_list ap);
char			*ft_ctostr(char c);
t_struct		*ft_initialize_rps(t_struct *rps);
void			ft_putstr(char *s, t_struct *rps);
t_struct		*ft_initialize_flags(t_struct *flags);
void			ft_putchar(char c, t_struct *rps);
int				ft_printf(const char *txt, ...);
void			ft_print_addr(long unsigned p, t_struct *rps);
void			ft_print_hex(long unsigned nbr, char *hex, t_struct *rps);
void			ft_flags(const char *txt, t_struct *rps, int j, va_list ap);
void			ft_parse_flags(t_struct *flags, char *all_flags, va_list ap);

#endif
