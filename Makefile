# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 14:13:30 by hcho2             #+#    #+#              #
#    Updated: 2023/07/12 15:28:12 by hcho2            ###   ########.fr        #
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
			srcs/key_press.c srcs/utils.c srcs/utils2.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c
BSRC		= bsrcs/main_bonus.c bsrcs/parse_input_bonus.c bsrcs/ft_split_bonus.c \
			bsrcs/ft_atoi_bonus.c bsrcs/draw_bonus.c bsrcs/scaling_bonus.c bsrcs/projection_bonus.c \
			bsrcs/key_press_bonus.c bsrcs/utils_bonus.c bsrcs/utils2_bonus.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ			= $(SRC:.c=.o)
BOBJ		= $(BSRC:.c=.o)

INC			= -Iincludes
NAME		= fdf
BNAME		= fdf_bonus
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -C ./mlx
	@$(CC) $(MFLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                          FDF DONE                          " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

bonus:		$(BNAME)

$(BNAME):	$(BOBJ)
	@$(MAKE) -C ./mlx
	@$(CC) $(MFLAGS) $(BOBJ) -o $(NAME)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                          FDF DONE                          " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@touch $@

%.o: 		%.c
	@$(CC) $(CFLAGS) -Imlx $(INC) -c $< -o $@

clean:
	@$(RM) mlx/*.o
	@$(RM) $(OBJ) $(BOBJ)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                          FDF CLEAN                         " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

fclean:		clean
	@$(RM) $(NAME) $(BNAME)
	@echo $(GREEN)"\n============================================================\n" $(EOC)
	@echo $(YELLOW)"                         FDF FCLEAN                         " $(EOC)
	@echo $(GREEN)"\n============================================================\n" $(EOC)

re:			fclean all

.PHONY:		clean fclean re
