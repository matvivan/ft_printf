# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matvivan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 14:53:43 by matvivan          #+#    #+#              #
#    Updated: 2020/10/05 01:45:43 by matvivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g -c
ARFLAGS = rc
SRC = ft_printf.c ft_str_print.c ft_decimal_print.c ft_math.c \
	ft_valid_fields.c ft_float_print.c ft_float_math.c

.PHONY: bonus fclean clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C libft/
	@mv libft/libft.a $(NAME)
	@$(CC) $(CFLAGS) $^
	@$(AR) $(ARFLAGS) $@ $(^:.c=.o)
	@echo "Library '$(NAME)': up-to-date."

clean:
	@$(RM) $(SRC:.c=.o)
	@echo "Directory: cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Library '$(NAME)': deleted."

bonus: re

re: fclean all
