# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <anazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/15 16:09:55 by anazar            #+#    #+#              #
#    Updated: 2017/10/19 15:23:44 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
SRC_DIR = ./src/
LIB_DIR = ./libft/
LIB = libft.a
FILES = main get_p_num get_board_y get_board_x get_board get_piece \
				get_indices get_map_indices save_map save_piece int_arr_len \
				place_piece get_corners
SRCS = $(addprefix $(SRC_DIR), $(patsubst %, %.c, $(FILES)))
OBJS = $(patsubst %, %.o, $(FILES))
INCLUDES = includes/
LIB_DIR = ./libft/
FLAGS = -Wall -Werror -Wextra -I./$(INCLUDES) -I$(LIB_DIR)/$(INCLUDES)
L_FLAGS = -L $(LIB_DIR) -lft

all :	$(NAME)

lib :
	@make -C libft/

$(NAME) : $(OBJS)
	@$(MAKE) lib
	@gcc $(OBJS) $(L_FLAGS) -o $(NAME)

$(OBJS) : $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

clean :
	@make -C libft/ clean
	@rm -rf *.o

fclean :
	@make -C libft/ fclean
	@$(MAKE) clean
	@rm -rf $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all
