NAME = get_next_line.a

CC = cc

FLAGS = -Wall -Wextra -Werror

M_SOURCES = get_next_line.c get_next_line_utils.c

B_SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c

M_OBJECTS = $(M_SOURCES:.c=.o)

B_OBJECTS = $(B_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJECTS)
	ar rc $(NAME) $(M_OBJECTS)

%.o: %.c get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(M_OBJECTS) $(B_OBJECTS)

fclean:
	rm -f $(M_OBJECTS) $(B_OBJECTS) $(NAME)

re: fclean all

bonus: $(B_OBJECTS)
	ar rc $(NAME) $(B_OBJECTS)

.PHONY: clean fclean all