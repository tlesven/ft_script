# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/16 18:15:45 by tlesven           #+#    #+#              #
#    Updated: 2014/04/30 23:10:09 by tlesven          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
MLIB = make -C ./libft
CFLAGS =  -Wextra -Werror -c -I ./libft/includes
LDFLAGS = -L ./libft -lft
RM = rm -rf

NAME = ft_script

SRC = main.c \
	  acces_functions.c \
	  ft_script.c \
	  ft_master.c \
	  ft_slave.c \
	  ft_tool.c \

OBJ=$(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
		$(MLIB)
		$(CC) -o $@ $(LDFLAGS) $^

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) $^

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./libft

re: fclean all

norme:
	norminette $(SRC) ft_script.h
