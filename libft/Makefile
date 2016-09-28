# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:30:43 by qhonore           #+#    #+#              #
#    Updated: 2016/09/23 08:45:47 by qhonore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		   ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		   ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		   ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		   ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		   ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		   ft_lstiter.c ft_lstmap.c ft_isspace.c ft_isblank.c \
		   ft_strprefix.c ft_strsuffix.c ft_lstgo.c ft_lstaddend.c \
		   ft_intlen.c ft_lstprint.c ft_lstndel.c ft_atoi_base.c \
		   ft_abs.c ft_pow.c ft_strisnb.c get_next_line.c \
		   ft_dlstnew.c ft_dlstadd.c ft_dlstaddend.c ft_dlstgo.c \
		   ft_dlstndel.c ft_free.c ft_itoa_base.c ft_utoa.c \
		   ft_utoa_base.c ft_utoa2.c ft_utoa_base2.c ft_itoa2.c \
		   ft_itoa_base2.c
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: init $(NAME)


$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: init supp clean fclean re

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: supp clean
	rm -f $(NAME)

re: fclean all
