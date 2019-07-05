NAME = ft_retro
FILES = srcs/main.cpp srcs/ship.cpp srcs/Entity.cpp srcs/box.cpp srcs/projectile.cpp -lncurses

all: $(NAME)

$(NAME): 
	@clang++ -o $(NAME) -Wall -Wextra -Werror $(FILES)

clean:
	@/bin/rm -rf $(NAME)

re: clean all
