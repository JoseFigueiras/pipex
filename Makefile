NAME		=	pipex

FLAGS		=	-Wall -Wextra -Werror
INCDIR		=	includes

SRCS		=	$(wildcard srcs/*.c)
			
OBJS		= 	$(SRCS:.c=.o)		\
				srcs/libft.a

all: $(OBJS)
	gcc $(OBJS) -o $(NAME)

srcs/libft.a:
	make -C srcs/libft
	mv srcs/libft/libft.a srcs/.

%.o: %.c
	gcc $< -c -o $@ -I$(INCDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
