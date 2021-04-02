# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 18:49:45 by jodufour          #+#    #+#              #
#    Updated: 2021/04/02 23:35:28 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	g++ -c -o
LINKER		=	g++ -o
RM			=	rm -rf
MAKEDIR		=	mkdir -p

NAME		=	sudoku
SRCD		=	srcs/
OBJD		=	objs/
INCLUDE		=	includes/
CLASSD		=	class/
CLASSD		:=	${addprefix ${INCLUDE}, ${CLASSD}}

CLASSES		=	grid.cpp

SRCS		=	\
				${CLASSES}		\
				main.cpp		\
				setup.cpp		\
				errMsg.cpp		\
				checkInput.cpp	\
				strchr.cpp		\
				solve.cpp		\
				pause.cpp

OBJS		=	${SRCS:.cpp=.o}
OBJS		:=	${addprefix ${OBJD}, ${OBJS}}
DEPS		=	${OBJS:.o=.d}

CPPFLAGS	=	-Wall -Wextra -I ${INCLUDE} -MMD
LDFLAGS		=	-lncurses

ifeq (${DEBUG}, TRUE)
	CPPFLAGS += -g
endif

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} $^

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.cpp
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CPPFLAGS} $<

${OBJD}%.o:	${CLASSD}%.cpp
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CPPFLAGS} $<

clean:
	${RM} ${OBJD} ${DEPS}

fclean:
	${RM} ${OBJD} ${DEPS} ${NAME}

re:	fclean all

.PHONY:	all clean fclean
