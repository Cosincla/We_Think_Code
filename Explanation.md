# We_Think_Code
Project stuff

Filler is a project that involves programming an AI in order to play a boardgame against another AI.
How to run:
make
./resources/filler_vm -p1 <player one>/Filler resources -p2 resources/players/<player 2> -f ./resources/maps/<map>

Push_Swap is a project that involves programming both a sorting algorithm and the Environment in which it runs.
How to run:
make
ARG="<5 numbers>"; ./push_swap $ARG | ./checker $ARG
PS:
you can play with just the checker itself by:
./checker <any numbers>
Commands:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there's only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there's only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Does nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Does nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element become the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

Lemin is a project that involves finding a path from a set map.
How to run:
make
./lem-in < map.map
PS:
you may see the path and the adjacency matrix used by running the program with the -p and -m respecively
e.g
./lem-in -p -v < map.map
