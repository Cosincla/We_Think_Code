# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cosincla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 11:35:53 by cosincla          #+#    #+#              #
#    Updated: 2018/08/03 10:58:10 by cosincla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
CFILES = ./map.c ./quad.c ./strat.c ./ai.c ./place.c 
LIBRARY = libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY) $(OFILES)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(CFILES) -I includes $(LIBRARY)

$(LIBRARY):
	make -C libft

clean:
	@/bin/rm -rf $(OFILES)
	make clean -C libft

fclean: clean
	@/bin/rm -rf $(NAME)
	make fclean -C libft

re: fclean all
