# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 00:23:00 by dravi-ch          #+#    #+#              #
#    Updated: 2023/05/25 14:45:02 by dravi-ch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE	=	ft_itoa.c ft_tolower.c ft_calloc.c ft_strrchr.c ft_toupper.c ft_strnstr.c ft_strjoin.c \
			ft_putchar_fd.c ft_strlcat.c ft_isalnum.c ft_striteri.c ft_strlen.c ft_memcmp.c ft_isprint.c \
			ft_strlcpy.c ft_putendl_fd.c ft_strncmp.c ft_substr.c ft_memmove.c ft_strchr.c ft_isalpha.c \
			ft_putstr_fd.c ft_memcpy.c ft_memset.c ft_putnbr_fd.c ft_isdigit.c ft_strtrim.c ft_strmapi.c \
			ft_memchr.c ft_split.c ft_isascii.c ft_strdup.c ft_bzero.c ft_atoi.c

OBJECTS	=	${SOURCE:.c=.o}

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.c.o	:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJECTS}
			ar rcs ${NAME} ${OBJECTS}

all		:	${NAME}

clean	:
			${RM} ${OBJECTS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re


