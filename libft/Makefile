# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efaustin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 19:14:31 by efaustin          #+#    #+#              #
#    Updated: 2024/10/18 19:14:33 by efaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC =	ft_strdup.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strlen.c \
		ft_split.c \
		ft_itoa.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_printf_convert.c \
		get_next_line.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
