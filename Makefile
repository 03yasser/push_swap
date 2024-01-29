SRCS_FILES = ft_split.c utils.c ft_lst.c sorting.c operation1.c operation2.c parcing.c a2b.c b2a.c b2a1.c main.c
OBJDIR = object_files
HEADER = includes/push_swap.h
SRCS = $(addprefix srcs/,$(SRCS_FILES))
OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all :$(NAME)

$(NAME) : $(OBJS) 
	cc $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o:srcs/%.c $(HEADER)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I ./includes -c $< -o $@
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)

re: fclean all