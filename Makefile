SRCS = ft_split.c libft.c ft_lst.c operation1.c operation2.c sorting.c parcing.c a2b.c b2a.c b2a1.c 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all :$(NAME)

$(NAME) : $(SRCS)
	cc $(SRCS)  main.c  -o $(NAME)
clean:
	rm -r $(OBJF)
fclean:
	rm -rf $(NAME)
re:fclean all