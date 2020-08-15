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

NAME = libftprintf.a

# compiling

GCC = gcc -Wall -Wextra -Werror -c

# paths

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

# files

SRC = 			 conv_to_f.c \
      			 conv_to_f2.c \
      			 conv_to_i.c \
      			 conv_to_o.c \
      			 conv_to_p.c \
      			 conv_to_s.c \
      			 conv_to_u.c \
      			 conv_to_x.c \
      			 for_lst.c \
      			 ft_itoabase.c \
      			 ft_itoau.c \
      			 ft_printf.c \
      			 make_format.c \
      			 make_format2.c \
      			 make_out.c
OBJ = $(patsubst %.c, %.o, $(SRC))
HEADER = includes
LIB = libft/libft.a

# files with dir

C_PATH = $(addprefix $(SRC_DIR), $(SRC))
O_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	@cp $(LIB) ./$(NAME)
	@ar -rc $(NAME) $(O_PATH)
	@ranlib $(NAME)

$(OBJ_DIR):
	@make -C $(LIB_DIR)
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(GCC) $< -o $@ -I $(HEADER) -I $(LIB_DIR)


fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIB_DIR)

clean:
	@ rm -f $(OBJ_PATH)
	@ rm -rf $(OBJ_DIR)
	@ make clean -C $(LIB_DIR)

re: fclean all
