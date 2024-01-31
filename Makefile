SRCS_FILES = ft_split.c utils.c ft_lst.c sorting.c operation1.c operation2.c operation3.c parcing.c a2b.c b2a.c b2a1.c main.c 
bonus_files = checker_bonus.c checker_utils_bonus.c checker_utils_bonus2.c ft_split_bonus.c gnl_bouns.c gnl_utils_bonus.c main.c operation1_bonus.c operation2_bonus.c operation3_bonus.c
OBJDIR1 = object_files1
OBJDIR2 = object_files2
HEADER = includes/push_swap.h includes/checker_bonus.h
SRCS = $(addprefix srcs/,$(SRCS_FILES))
OBJS = $(addprefix $(OBJDIR1)/,$(notdir $(SRCS:.c=.o)))
BSRCS = $(addprefix bonus_srcs/,$(bonus_files))
BOBJS = $(addprefix $(OBJDIR2)/,$(notdir $(BSRCS:.c=.o)))
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all :$(NAME)
$(NAME) : $(OBJS) 
	cc $(CFLAGS) $^ -o $@
$(OBJDIR1)/%.o:srcs/%.c $(HEADER)
	mkdir -p $(OBJDIR1)
	$(CC) $(CFLAGS) -I ./includes -c $< -o $@
$(OBJDIR2)/%.o:bonus_srcs/%.c $(HEADER)
	mkdir -p $(OBJDIR2)
	$(CC) $(CFLAGS) -I ./includes -c $< -o $@
bonus: $(BOBJS)
	cc  $(CFLAGS) $(BOBJS)  -o checker
clean:
	rm -rf $(OBJDIR1) $(OBJDIR2)
fclean: clean
	rm -f $(NAME) checker
re: fclean all