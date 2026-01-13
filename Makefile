# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 15:10:14 by nmontard          #+#    #+#              #
#    Updated: 2026/01/13 16:59:41 by aslimani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -MMD -MP -I headers -g
PRINTF_PATH = ft_printf
DIR_TO_CREATE = obj_and_dep_dir obj_and_dep_dir/$(PRINTF_PATH)
PRINTF_FILES = $(PRINTF_PATH)/ft_printf_helper1.c $(PRINTF_PATH)/ft_printf.c $(PRINTF_PATH)/ft_put_hex_nbr.c \
$(PRINTF_PATH)/ft_put_memory.c
CFILES = push.c swap.c list_utils.c main.c quick_sort.c reverse_rotate.c rotate.c swap.c $(PRINTF_FILES) \
selection_sort_partition.c selection_sort_partition_one_way.c quick_sort_utils.c medium_algo.c simple_algo.c \
medium_utils.c medium_utils_2.c
OBJECTS = $(addprefix obj_and_dep_dir/, $(CFILES:.c=.o))
DEPS = $(addprefix obj_and_dep_dir/, $(CFILES:.c=.d))
NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $^ -o $@ 

obj_and_dep_dir/%.o: %.c
	mkdir -p $(DIR_TO_CREATE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_TO_CREATE)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
