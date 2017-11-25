# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:33:10 by xperrin           #+#    #+#              #
#    Updated: 2017/11/25 20:25:45 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SONAME = $(NAME:.a=.so)
CC = clang
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I.

FT_LIBC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c
FT_42 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FT_BONUS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
FT_CUSTOM = ft_islower.c ft_isupper.c ft_strupcase.c ft_strlowcase.c \
	ft_cntword.c ft_strrlen.c ft_strndup.c \
	ft_cntdigit.c ft_pow.c
SRC = $(FT_LIBC) $(FT_42) $(FT_CUSTOM) $(FT_BONUS)
OBJ = $(SRC:.c=.o)

.PHONY: all so clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Archived library updated"

$(SONAME): CFLAGS += -fPIC
$(SONAME): $(OBJ)
	@$(CC) -shared -o $(SONAME) $(OBJ)
	@echo "Shared object updated"

so: $(SONAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(SONAME)

re: fclean all
