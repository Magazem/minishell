.SILENT: ${NAME}

SRCSDIR = ./srcs
SRCS =  main.c signals.c lexer.c lexer_helpers.c print_lexer.c
OBJDIR = ./objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
HEADER = ./includes/minishell.h
NAME = minishell

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
LIBFT_URL = https://github.com/Magazem/libft.git  

cc = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS =  -lreadline -ltinfo

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
	${cc} -g $(OBJS) -L./libft -lft $(LDFLAGS) -o $(NAME)
	@echo "$(CYAN)OBJS compiling..."
	@echo "$(RED)$(BOLD)⤙ minishell: $(GREEN)compiled and ready $(LIGHT_YELLOW)[$(GREEN)✔$(LIGHT_YELLOW)]$(RED)$(BOLD) ⤚"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) --no-print-directory bonus -C $(LIBFTDIR)

$(LIBFTDIR):
	@echo "$(CYAN)Downloading libft...$(NORMAL)"
	git clone -q $(LIBFT_URL) $(LIBFTDIR)
	@echo "$(GREEN)Libft downloaded successfully$(NORMAL)"

clean:
	@$(MAKE) -s clean -C $(LIBFTDIR) 2>/dev/null || true
	@${RM} -r $(OBJDIR)
	@echo "$(RED)$(CUT)cleaning OBJS 🗑"

fclean:	clean
	@${RM} -r $(LIBFTDIR)
	@${RM} ${NAME}
	@echo "$(RED)$(UP)cleaning everything 💣"

re: fclean all

.PHONY: all clean fclean re