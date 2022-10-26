# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 09:25:45 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/10/22 20:27:44 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRC 	=	command_path.c pipex.c

OBJ		=	$(SRC:%.c=%.o)

LIBFT	=	libft/libft.a

HEADER	=	pipex.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -g

RM		= rm -rf

.PHONY:		all	clean	fclean	re	libft

all:		libft $(NAME)
			
libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C libft/ clean

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)

re:			fclean all