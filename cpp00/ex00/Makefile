#################### ARGUMENTS ####################

NAME = megaphone

CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++98

#################### SOURCES ####################

# Sources
SRCS_DIR			= src/

SRCS				= megaphone.cpp

SOURCES				= $(addprefix $(SRCS_DIR), $(SRCS))

# Objects
OBJS_DIR			= objs/
OBJS				= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

#################### RULES ####################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(BOLD)  ✅ Compilation done $(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	@echo "$(ORANGE) $(BOLD)  ⏳ Compilation in progress$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GRAY) $(BOLD) 🗑️  Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW) $(BOLD) 🧹 Cleaning done$(RESET)"

re: fclean all

# -include $(OBJS:.o=.d)

.PHONY: all clean fclean re

#################### STYLES ####################

GRAY		= \033[90m
GREEN		= \033[33;32m
ORANGE		= \033[38;5;214m
# RED			= \033[31m
YELLOW		= \033[33m

BOLD		= \033[1m
RESET		= \033[0m
