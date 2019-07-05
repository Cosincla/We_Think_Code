NAME = whatever
FILES = whatever.cpp

all: $(NAME)

$(NAME): 
	@clang++ -o $(NAME) -Wall -Wextra -Werror $(FILES)

clean:
	@/bin/rm -rf $(NAME)

re: clean all
