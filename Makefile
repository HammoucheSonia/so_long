NAME= so_long

SRC = main.c final.c create_map.c play_utils2.c verif.c data.c get_next_line.c play_utils.c get_next_line_utils.c  play.c utils.c

CC      = gcc
FLAGS	= -Werror -Wextra -Werror -g -I.

ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif

OBJ = $(SRC:.c=.o)

MLX = ./minilibx-linux/libmlx.a

LIB =  -L./minilibx-linux -lmlx -lXext -lX11 -lm

${NAME}: ${OBJ} ${MLX}
	$(CC) $(OBJ) $(LIB) -o $@

target/ruleName: dep0 dep1 dep2 ... depN
	instruct 0
	instruct 1
	...
	$< la premiere dep
	$@ la target
	$^ 



%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(MLX):
	make -C ./minilibx-linux

clean:

	make clean -C ./minilibx-linux
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}
	

re: fclean all

.PHONY : all clean fclean re 
