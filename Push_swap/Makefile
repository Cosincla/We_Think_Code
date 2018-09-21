# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cosincla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 13:01:05 by cosincla          #+#    #+#              #
#    Updated: 2018/08/24 13:49:58 by cosincla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
CFILES = ./auxfun.c ./funca.c ./funcb.c ./funcr.c
MAIN1 = ./chmain.c
MAIN2 = ./psmain.c ./ifelse.c
LIBRARY = ./libft/libft.a

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBRARY)
	@gcc -o $(NAME1) -Wall -Wextra -Werror $(MAIN1) $(CFILES) $(LIBRARY)

$(NAME2): $(LIBRARY)
	@gcc -o $(NAME2) -Wall -Wextra -Werror $(MAIN2) $(CFILES) $(LIBRARY)

$(LIBRARY):
	@make -C ./libft

clean:
	@make clean -C ./libft

fclean: clean
	@/bin/rm -rf $(NAME1)
	@/bin/rm -rf $(NAME2)
	@make fclean -C ./libft

re: fclean all
