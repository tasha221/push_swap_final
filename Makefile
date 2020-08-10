

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amariett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 18:00:03 by amariett          #+#    #+#              #
#    Updated: 2020/02/01 19:20:07 by amariett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Wextra -Werror -c

all:
	make checker
	make push_swap

push_swap:
	@ make -C libft/
	@ make -C ft_printf/
	@ cp libft/libft.a .
	@ cp ft_printf/libftprintf.a .
	@ gcc $(FLAGS) functions.c for_stack.c push_swap.c push_swap_dop.c \
		dop_sort.c make_res.c make_sort.c valid_errors.c for_parse.c
	@ gcc functions.o for_stack.o push_swap.o push_swap_dop.o dop_sort.o \
		make_res.o make_sort.o valid_errors.o for_parse.o \
		libft.a libftprintf.a -o push_swap

checker:
	@ make -C libft/
	@ make -C ft_printf/
	@ cp libft/libft.a .
	@ cp ft_printf/libftprintf.a .
	@ gcc $(FLAGS) functions.c for_stack.c get_next_line.c checker.c visual.c valid_errors.c for_parse.c
	@ gcc functions.o for_stack.o get_next_line.o checker.o visual.o valid_errors.o for_parse.o libft.a libftprintf.a -o checker

clean:
	@ rm -rf ft_printf/obj
	@ rm -rf libft/*.o
	@ rm -rf ft_printf/libft/*.o
	@ rm -rf dop_sort.o for_parse.o for_stack.o functions.o make_res.o make_sort.o \
		push_swap.o push_swap_dop.o valid_errors.o checker.o visual.o \
		get_next_line.o

fclean: clean
	@ rm -rf ft_printf/libftprintf.a
	@ rm -rf libft/libft.a
	@ rm -rf push_swap checker libft.a libftprintf.a

re: fclean
	@ make all