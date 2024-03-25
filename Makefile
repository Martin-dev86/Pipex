# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 12:45:34 by cagarci2          #+#    #+#              #
#    Updated: 2024/03/22 12:45:34 by cagarci2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = 

BONUS = 

OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
CC = gcc
CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)

	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)

	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%o: %c

	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re