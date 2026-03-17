#################### ARGUMENTS ####################

NAME = bureaucrat

CPP = c++

#################### SOURCES ####################

# Includes
INCLUDES = -Iincludes

FLAGS = -Wall -Werror -Wextra -MMD -MP -Wno-shadow -Wshadow -std=c++98 -g

# Sources
SRCS_DIR			= srcs/

SRCS				= main.cpp \
					Bureaucrat.cpp

SOURCES				= $(addprefix $(SRCS_DIR), $(SRCS))

# Objects
OBJS_DIR			= objs/
OBJS				= $(SOURCES:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

#################### RULES ####################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN) $(BOLD)  ✅ Compilation done $(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	@$(CPP) $(INCLUDES) $(FLAGS) -c $< -o $@
	@echo "$(ORANGE) $(BOLD)  ⏳ Compilation in progress$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GRAY) $(BOLD) 🗑️  Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW) $(BOLD) 🧹 Cleaning done$(RESET)"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re

#################### STYLES ####################

GRAY		= \033[90m
GREEN		= \033[33;32m
ORANGE		= \033[38;5;214m
YELLOW		= \033[33m

BOLD		= \033[1m
RESET		= \033[0m
