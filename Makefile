CFLAGS	= -Wall -Werror -Wextra

SRCS	=	ft_printf2.c

CC	=	gcc
RM	=	rm -f
	
INCLUDES=	


 ## gcc ft_printf2.c ${FLAGS} -I../0lvl_libft_1week/ -L../0lvl_libft_1week/ -lft -o ft_printf2

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

all:	${NAME}

.c.o:
	${CC} ${FLAGS} -I. -L./libft/ -lft -c $< -o ${<:.c=.o}

${NAME}:libft.a ${OBJS}
	ar rcs	${NAME} $ ${OBJS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re:	fclean all

libft.a:	
	make -C ./libft
