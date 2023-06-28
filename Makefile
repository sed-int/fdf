# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 14:13:30 by hcho2             #+#    #+#              #
#    Updated: 2023/06/28 20:40:08 by hcho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

SRC			= srcs/main.c srcs/parse_input.c srcs/ft_split.c \
			srcs/ft_atoi.c srcs/draw.c srcs/scaling.c srcs/projection.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ			= $(SRC:.c=.o)

NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(MFLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                          FDF DONE                          " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

%.o: 		%.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                          FDF CLEAN                         " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

fclean:		clean
	@$(RM) $(NAME)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                         FDF FCLEAN                         " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

re:			fclean all

.PHONY:		clean fclean re
