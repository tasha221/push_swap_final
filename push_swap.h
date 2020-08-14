/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTITLED_PUSH_SWAP_H
# define UNTITLED_PUSH_SWAP_H
# define BUFF_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/printf.h"

typedef struct		s_elem
{
	int				n;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_stack
{
	int				name;
	int				size;
	t_elem			*first;
	t_elem			*last;
}					t_stack;

t_stack				*make_stack(int *mas, int size, int name, int fl);
t_elem				*make_elem(int n);
void				visual(t_stack *astack, t_stack *bstack);
void				swap(t_stack *stack, char **res);
void				push(t_stack *to, t_stack *from, char **res);
void				rotate(t_stack *stack, char **res);
void				rrotate(t_stack *stack, char **res);
int					get_next_line(int fd, char **line);
int					apply_oper(char *buf, t_stack *a, t_stack *b, char **res);
int					is_sorted(t_stack *a, t_stack *b);
void				free_stack(t_stack *stack);
void				for_error(t_stack *a, t_stack *b);
int					is_valid_input(char **av, int ac, int check);
int					*make_mas(char **argv, int argc);
void				bubble(int size, int *mas);
void				make_both(char *buf, t_stack *a, t_stack *b, char **res);
int					*make_mas_num(t_stack *a, t_stack *b, int *num);
void				make_push(t_stack *a, t_stack *b, int j, char **res);
int					f_min(int a, int b);
int					find_best_i(t_stack *a, int max, int fl);
int					find_min_a(t_stack *a_stack, int num, int fl);
void				make_final_ra(t_stack *a, char **res);
char				**argvdup(int argc, char **argv);
char				**parse_input(char **argv, char **arr);
int					arr_len(char **arr);
void				free_arr(char **arr);
char				*make_for_five(t_stack *a, t_stack *b, int *mas);
int					is_cycled(t_stack *a);
int					push_swap2(t_stack *a, t_stack *b, char **arr, int *mas);
char				*sort(t_stack *a, t_stack *b, int *mas);

#endif
