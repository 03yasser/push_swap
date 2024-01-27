SRCS = ft_split.c libft.c ft_lst.c operation.c sorting.c a_b.c
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all :$(NAME)

$(NAME) : $(SRCS)
	cc $(CFLAGS) $(SRCS)  main.c  -o $(NAME)
clean:
	rm -r $(OBJF)
fclean:
	rm -rf $(NAME)
re:fclean all