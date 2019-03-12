# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 17:36:55 by ebatchas          #+#    #+#              #
#    Updated: 2018/12/25 22:51:36 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
HEADDIR=includes
LIBDIR=libs
BINDIR=.

CFLAGS=-Wall -Wextra -Werror

NAME = libftprintf.a

SRC=$(SRCDIR)/ft_printf.c

OBJ=$(LIBDIR)/ft_printf.o\
	$(LIBDIR)/libft/*.o

all : $(NAME)
$(NAME) :
	make re -C $(LIBDIR)/libft
	$(CC) $(CFLAGS) $(SRC) -c
	mv ft_printf.o $(LIBDIR)/
	ar rc $@ $(OBJ)
	ranlib $@

$(LIBDIR)/%.o:$(HEADDIR)/%.h
$(LIBDIR)/%.o:$(SRCDIR)/%.c

.PHONY: clean fclean

clean:
	rm -rf $(LIBDIR)/*.o

fclean: clean
	rm -rf $(BINDIR)/$(NAME)

re: fclean all
