JEBAC_PRINTF	= -Wall -Werror -Wextra

SRCS	=	ft_printfMain.c ft_flags_utils.c ft_utils.c ft_hexa_utils.c ft_c.c ft_s.c ft_p.c ft_u.c ft_x.c ft_d.c

CC	=	gcc
RM	=	rm -f
	
OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

all:	${NAME}

.c.o:
	${CC} ${JEBAC_PRINTF} -I. -c $< -o ${<:.c=.o} 

${NAME}:libft.a ${OBJS}
	ar rcs	${NAME} ${OBJS} ./libft/*o

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

libft.a:	
	make -C ./libft
