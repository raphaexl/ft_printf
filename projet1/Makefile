# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 17:36:55 by ebatchas          #+#    #+#              #
#    Updated: 2018/12/26 14:54:20 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
HEADDIR=includes
LIBDIR=libs
BINDIR=.

CFLAGS=-Wall -Wextra -Werror

NAME = libftprintf.a

SRC=$(SRCDIR)/ft_printf.c\
	$(SRCDIR)/print_format1.c\
	$(SRCDIR)/print_format2.c\
	$(SRCDIR)/ft_get_format.c\
	$(SRCDIR)/ft_itoa_base.c\
	$(SRCDIR)/utils.c


OBJ=$(LIBDIR)/ft_printf.o\
	$(LIBDIR)/print_format1.o\
	$(LIBDIR)/print_format2.o\
	$(LIBDIR)/ft_get_format.o\
	$(LIBDIR)/ft_itoa_base.o\
	$(LIBDIR)/utils.o\
	$(LIBDIR)/libft/*.o

$(LIBDIR)/%.o:$(HEADDIR)/%.h
$(LIBDIR)/%.o:$(SRCDIR)/%.c

all : $(NAME)
$(NAME) :
	make re -C $(LIBDIR)/libft
	$(CC) $(CFLAGS) $(SRC) -c
	mv *.o $(LIBDIR)/
	ar rc $@ $(OBJ)
	ranlib $@


.PHONY: clean fclean

clean:
	make clean -C $(LIBDIR)/libft
	rm -rf $(LIBDIR)/*.o

fclean: clean
	make fclean -C $(LIBDIR)/libft
	rm -rf $(BINDIR)/$(NAME)

re: fclean all
