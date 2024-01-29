SRCS = ft_split.c utils.c ft_lst.c sorting.c operation1.c operation2.c parcing.c a2b.c b2a.c b2a1.c
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all :$(NAME)

$(NAME) : $(SRCS)
	cc $(SRCS) $(CFLAGS)  main.c  -o $(NAME)
clean:
	rm -r $(OBJF)
fclean:
	rm -rf $(NAME)
re:fclean all