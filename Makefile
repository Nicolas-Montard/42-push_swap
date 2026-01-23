# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 15:10:14 by nmontard          #+#    #+#              #
#    Updated: 2026/01/23 16:50:09 by aslimani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -MMD -MP -I headers -g
LIBFT_PATH = libft
PRINTF_PATH = ft_printf
PRINTF_FILES := ft_printf_helper1.c ft_printf.c ft_put_hex_nbr.c ft_put_memory.c
PRINTF_FILES := $(addprefix $(PRINTF_PATH)/, $(PRINTF_FILES))
LIBFT_FILES := ft_bzero.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_memmove.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIBFT_FILES := $(addprefix $(LIBFT_PATH)/, $(LIBFT_FILES))
DIR_TO_CREATE = obj_and_dep_dir obj_and_dep_dir/$(PRINTF_PATH) obj_and_dep_dir/$(LIBFT_PATH)
CFILES = push.c swap.c list_utils.c main.c quick_sort.c reverse_rotate.c rotate.c swap.c $(PRINTF_FILES) \
selection_sort_partition.c selection_sort_partition_one_way.c quick_sort_utils.c chunk_sort.c selection_sort.c \
chunk_sort_utils.c chunk_sort_utils_2.c parsing.c benchmark.c disorder_metric.c adaptive.c normalize_numbers.c \
parsing_verif_numbers.c utils_stack.c utils_algo.c utils.c $(LIBFT_FILES)
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
