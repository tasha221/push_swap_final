/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int					ft_printf(const char *str, ...);

typedef struct		s_lst
{
	char			type;
	char			*len;
	int				width;
	int				precision;
	char			*out;
	int				zero;
	int				min;
	int				plus;
	int				space;
	int				hash;
	int				for_null;
	struct s_lst	*next;
}					t_lst;

t_lst				*lst_create(char *s, va_list *v);
void				lst_add(t_lst **head, t_lst *new);
void				make_format(char *s, t_lst *lst, va_list *v);
void				make_out(t_lst *lst, va_list *val);
void				conv_to_s(t_lst *lst, va_list *val);
void				conv_to_c(t_lst *lst, va_list *val);
void				make_width(char **tmp, t_lst *lst, char c, int width);
char				*ft_itoabase16(unsigned long long int n, int base, int up);
void				conv_to_p(t_lst *lst, va_list *val);
size_t				len_num(unsigned long long int n, int base);
void				conv_to_i(t_lst *lst, va_list *val);
char				*ft_itoalong(long long int n, int size);
size_t				len_numlong(long long int n);
void				conv_to_u(t_lst *lst, va_list *val);
char				*ft_itoau(unsigned long long n, int size);
size_t				len_numu(unsigned long long int n);
void				make_width_i(char **tmp, t_lst *lst, int i, int len);
void				make_len_u(t_lst *lst, unsigned long long *b, va_list *val);
void				make_prec_u(char **tmp, t_lst *lst);
void				make_prec_u2(char **tmp, t_lst *lst, int len, int prec);
char				*ft_itoabase8(unsigned long long n, int s, int b, int u);
void				conv_to_o(t_lst *lst, va_list *val);
void				conv_to_x(t_lst *lst, va_list *val, int up);
void				conv_to_f(t_lst *lst, va_list *val);
char				*ft_lltoa(long long n);
long double			ft_ldtoa_adder(int prec);
void				make_width_f(char **tmp, t_lst *lst);
char				*make_fl_f(char *tmp, t_lst *lst);
void				make_zero(char **tmp);
int					make_format_add(int i, char *s, t_lst *lst, va_list *val);
int					make_int(char *s, int i);

#endif
