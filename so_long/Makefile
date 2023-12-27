NAME = so_long
CC = gcc
CFLAGS_WARN=-Wall -Wextra -Werror
OTHERS = minilibx/libmlx.a
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c so_long_main.c so_long_map_control.c so_long_points.c so_long_utils.c so_long_press.c so_long_counters.c so_long_initialize.c so_long_trial.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(OTHERS):
	make -C minilibx/

$(NAME): $(OBJS) $(OTHERS)
	$(CC) $(OBJS) -Iincludes -framework OpenGL -framework AppKit -o $(NAME) $(OTHERS)


clean :
	rm -f  so_long_main.o so_long_map_control.o so_long_points.o so_long_utils.o so_long_press.o so_long_counters.o so_long_initialize.o so_long_trial.o
	rm -f ./gnl/get_next_line_utils.o

fclean : clean
	rm -rf $(NAME)
	rm -rf gnl/get_next_line.o

re : fclean all

.PHONY : all fclean clean re
