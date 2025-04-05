# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 20:26:22 by zlee              #+#    #+#              #
#    Updated: 2025/04/05 17:40:34 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	  ft_strchr.c ft_strrchr.c ft_strrncmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_printf.c ft_printf_utils.c get_next_line.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_lstfirst.c ft_lstdup.c

NAME = libft.a

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc 

all : $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	@echo "Compiling libft bonus"
	@ar rcs $(NAME) $^
	@echo "Done!"

$(NAME) : $(OBJ)
	@echo "Compiling libft"
	@ar rcs $@ $^
	@echo "Done!"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "Done!"

fclean: clean
	@echo "Cleaning Executable..."
	@rm -f $(NAME)
	@echo "Done!"

re : fclean all

.PHONY: bonus all clean fclean re
