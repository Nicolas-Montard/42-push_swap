# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 15:10:14 by nmontard          #+#    #+#              #
#    Updated: 2025/12/09 16:35:06 by nmontard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -MMD -MP -I headers
PRINTF_PATH = ft_printf
PRINTF_FILES = $(PRINTF_PATH)/ft_printf_helper1.c $(PRINTF_PATH)/ft_printf.c $(PRINTF_PATH)/ft_put_hex_nbr.c \
$(PRINTF_PATH)/ft_put_memory.c
CFILES = push.c swap.c $(PRINTF_FILES) main.c
OBJECTS = $(CFILES:.c=.o)
DEPS  := $(OBJECTS:.o=.d)
NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJECTS) 
	$(CC) $^ -o $@ 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
