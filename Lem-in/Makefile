# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cosincla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 12:04:45 by cosincla          #+#    #+#              #
#    Updated: 2018/09/19 14:32:29 by cosincla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CFILES = ./darr.c ./auxfun.c ./checks.c ./main.c ./matrix.c ./print.c
LIBRARY = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY)
	@gcc -o $(NAME) -Wall -Wextra -Werror $(CFILES) $(LIBRARY)

$(LIBRARY):
	@make -C ./libft

clean:
	@make clean -C ./libft

fclean: clean
	@/bin/rm -rf $(NAME)
	@make fclean -C ./libft

re: fclean all
