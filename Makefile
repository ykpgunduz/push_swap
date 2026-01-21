# **************************************************************************** #
#                                                                              #
#                                                            :::      :::::::  #
#    Makefile                                              :+:      :+:    :+: #
#                                                        +:+ +:+         +:+   #
#    By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+      #
#                                                    +#+#+#+#+#+   +#+         #
#    Created: 2025/12/02 22:51:47 by yagunduz             #+#    #+#           #
#    Updated: 2026/01/21 21:43:56 by yagunduz            ###   ########.tr     #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CORE_SRC = $(SRC_DIR)/core/stack_manager.c \
           $(SRC_DIR)/core/node_manager.c \
           $(SRC_DIR)/core/stack_analyzer.c

OPS_SRC = $(SRC_DIR)/ops/op_push.c \
          $(SRC_DIR)/ops/op_swap.c \
          $(SRC_DIR)/ops/op_rotate.c \
          $(SRC_DIR)/ops/op_reverse_rotate.c

ALGO_SRC = $(SRC_DIR)/algorithm/tiny_sort.c \
           $(SRC_DIR)/algorithm/mini_sort.c \
           $(SRC_DIR)/algorithm/radix_sort.c \
           $(SRC_DIR)/algorithm/sort_dispatcher.c

PARSER_SRC = $(SRC_DIR)/parser/arg_parser.c \
             $(SRC_DIR)/parser/input_validator.c \
             $(SRC_DIR)/parser/error_handler.c

MAIN_SRC = $(SRC_DIR)/main.c

SRCS = $(CORE_SRC) $(OPS_SRC) $(ALGO_SRC) $(PARSER_SRC) $(MAIN_SRC)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
