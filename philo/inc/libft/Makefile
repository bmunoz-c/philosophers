NAME		=	libft.a

SRC			=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_memchr.c ft_memcmp.c ft_memcpy.c\
				ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c\
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strcmp.c ft_strrchr.c ft_strnstr.c\
				ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_strmapi.c ft_striteri.c ft_itoa.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_is_space.c ft_search_ch.c ft_index_ch.c\
				ft_strtrimfree.c ft_is_metachar.c ft_strjoin_f.c ft_free_ptr.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c


#_____Colors_____#
DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CIAN		=	\033[1;36m

#_____Directories_____#
BIN_DIR		=	bin/

#_____Binaries_____#
OBJS		=	$(SRC:%.c=$(BIN_DIR)%.o)
DEPS		=	$(OBJS:%.o=%.d)

#_____Includes_____#
INCLUDE		=	libft.h Makefile

#_____Commands_____#
LIB			=	ar -rcs
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
RM			=	rm -f


#BONUSSRC	=

#BONUSOBJ	= $(BONUSSRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			@$(LIB) $(NAME) $(OBJS)
			@echo "$(BLUE)Object linked and executable $(RED)$(NAME) $(BLUE)created!$(DEF_COLOR)"

#bonus: 	$(OBJ) $(BONUSOBJ) $(INCLUDE)
#			$(LIB) $(NAME) $(OBJ)

$(BIN_DIR)%.o: %.c $(INCLUDE)
			@mkdir -p $(BIN_DIR) $(BIN_DIR)get_next_line
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(WHITE_BOLD)Object$(YELLOW) $@ $(GREEN)compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(BIN_DIR)
			@echo "$(GREEN)Clean succesffull!$(DEF_COLOR)"

fclean:
			@$(RM) -rf $(BIN_DIR)
			@$(RM) $(NAME)
			@echo "$(GREEN)Full clean successfull!$(DEF_COLOR)"

re:			fclean all

.PHONY: all clean fclean re
#rebonus: fclean bonus\
