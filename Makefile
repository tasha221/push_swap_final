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


FLAGS = -Wall -Wextra -Werror
LIB_DIR = libft/
LIB_DIR1 = ft_printf/

all:
	make checker
	make push_swap

push_swap:
	@ make -C libft/
	@ make -C ft_printf/
	@ cp libft/libft.a .
	@ cp ft_printf/libftprintf.a .
	@ gcc $(FLAGS) functions.c for_stack.c push_swap.c push_swap_dop.c \
		dop_sort.c make_res.c make_sort.c valid_errors.c for_parse.c libft.a libftprintf.a -o push_swap

checker:
	@ make -C libft/
	@ make -C ft_printf/
	@ cp libft/libft.a .
	@ cp ft_printf/libftprintf.a .
	@ gcc $(FLAGS) functions.c for_stack.c get_next_line.c checker.c visual.c valid_errors.c for_parse.c libft.a libftprintf.a -o checker

clean:
	@ make clean -C $(LIB_DIR)
	@ make clean -C $(LIB_DIR1)

fclean: clean
	@ make fclean -C $(LIB_DIR)
	@ make fclean -C $(LIB_DIR1)
	@ rm -rf push_swap checker libft.a libftprintf.a

re: fclean
	@ make all