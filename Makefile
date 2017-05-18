# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 13:03:38 by sfranc            #+#    #+#              #
#    Updated: 2017/05/18 19:38:02 by sfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = 	$(addprefix $(SRCS_PATH)/, main.c \
		pixel.c \
		draw.c \
		events.c)
OBJS =  $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
INCLUDES = includes minilibx
LIB = $(LIB_PATH)/libmlx.a
LIB_PATH = minilibx
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
GREEN = \033[01;32m
YELLOW = \033[01;33m
CYAN = \033[01;36m
RESET = \033[00m

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) $(MLX_FLAGS) -o $@ $^
	@echo "$(GREEN)$@ : compilation OK$(RESET)"

$(LIB):
	@make -C $(LIB_PATH)
	@echo "$(GREEN)$(LIB) : compilation OK$(RESET)"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(INCLUDES)
	@$(CC) $(FLAGS) -o $@ -c $< $(addprefix -I , $(INCLUDES))
	@echo "$@ : $(YELLOW)OK$(RESET)"

clean:
	@make clean -C $(LIB_PATH)
	@echo "clean $(LIB_PATH)/objs : $(CYAN)clean$(RESET)"
	@echo "clean $(LIB) : $(CYAN)clean$(RESET)"
	@rm -f $(OBJS)
	@echo "clean $(OBJS): $(CYAN)clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "clean $(NAME) : $(CYAN)clean$(RESET)"

re: fclean all

.PHONY: clean fclean re
