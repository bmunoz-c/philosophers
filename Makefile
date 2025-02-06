NAME 			=	philo
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
##CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=thread


LIBS			=	-lpthread -Linc/libft -lft
INCLUDE			=	-Iinc

HEADER			= 	inc/philo.h

SRC_DIR 		= 	src/
OBJ_DIR 		= 	obj/
SRC 			:=	main.c \
					init.c utils.c philo.c

SRC				:=	$(addprefix $(SRC_DIR), $(SRC))
OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#_____Colors_____#
DEF_COLOR	=		\033[1;39m
WHITE_BOLD	=		\033[1m
RED			=		\033[1;31m
GREEN		=		\033[1;32m
YELLOW		=		\033[1;33m
BLUE		=		\033[1;34m
CIAN		=		\033[1;36m

LIBFT_EXEC		=	inc/libft/libft.a

all : $(NAME)

re : fclean all

$(NAME) : $(OBJ) $(LIBFT_EXEC) | libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)
	@echo "$(RED)$(NAME) $(BLUE)is ready to work!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) Makefile $(LIBFT_EXEC) | $(OBJ_DIR) libft
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(WHITE_BOLD)Object$(YELLOW) $@ $(GREEN)compiled!$(DEF_COLOR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(WHITE_BOLD)Created obj dir!$(DEF_COLOR)"

libft: $(LIBFT_EXEC)

$(LIBFT_EXEC):
	@$(MAKE) -C inc/libft --no-print-directory

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean 
	@$(MAKE) -C inc/libft fclean --no-print-directory
	@rm -f $(NAME)


.PHONY : all clean fclean re