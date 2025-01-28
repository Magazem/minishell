.SILENT: ${NAME} ${LIBFT}

SRCS = main.c
OBJS := $(SRCS:%.c=%.o)
HEADER = minishell.h
NAME = minishell

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

cc = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS = -lreadline

#Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHT_YELLOW = \033[1;33m
BOLD		= \033[1m
NORMAL		= \033[0m
UP			= \033[A
CUT			= \033[K
CYAN 		= \033[0;36m

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	@${CC} -g ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} -L./libft -lft	
	@echo "$(CYAN)OBJS compiling..."
	@echo "$(RED)$(BOLD)⤙ minishell: $(GREEN)compiled and ready $(LIGHT_YELLOW)[$(GREEN)✔$(LIGHT_YELLOW)]$(RED)$(BOLD) ⤚"

$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@${RM}	${OBJS} 
	@echo "$(RED)$(CUT)cleaning OBJS 🗑"

fclean:	clean
		@$(MAKE) fclean -C $(LIBFTDIR)
		@${RM} ${NAME}
		@echo "$(RED)$(UP)cleaning everything 💣"

re: fclean all

.PHONY: all clean fclean re