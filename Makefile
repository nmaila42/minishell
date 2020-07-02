FLAG = -Wall -Wextra -Werror

NAME = minishell

SRC = main.c ft_split.c ft_execute.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc  -o  $(NAME) $(FLAG) $(OBJ) get_next_line/get_next_line.c libft/libft.a 
	echo "$(NAME) created"

$(OBJ): %.o: %.c
	gcc -c $< -o $@
	echo "Objects created"

clean:
	rm -rf *.o
	echo "Objects deleted"

fclean: clean
	rm -rf $(NAME)
	echo "$(NAME) Deleted"

re: fclean all