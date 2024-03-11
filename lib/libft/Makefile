# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 08:35:36 by leobarbo          #+#    #+#              #
#    Updated: 2024/03/11 15:30:56 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = libft.a
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
.SILENT:

#! ******************************************************************************#
#                                   COLORS                                       #
#! ******************************************************************************#

GREEN = \033[32m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
FCOLOR = \033[0m
ORANGE=\033[93m
DARK_BLUE=\033[34m

#! ******************************************************************************#
#                                   PATH                                         #
#! ******************************************************************************#

SRCS_PATH = ./
BUILD_DIR := build/

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS := $(addprefix $(SRCS_PATH),\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isspace.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_split.c\
		ft_lstnew.c \
		ft_lstmap.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstpickel.c \
		ft_lstpop.c \
		ft_lstnewelement.c \
		ft_lstadd_after.c \
		ft_lstadd_before.c \
		ft_atol.c \
		ft_freesplit.c \
		ft_dolstadd_back.c \
		ft_dolstadd_front.c)

OBJS := $(SRCS:%.c=$(BUILD_DIR)%.o)

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.001
CC = cc
AR := ar -rcs
COUNT ?= 0

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS = -lft -ldl -lglfw -pthread
LDFLAGS = $(addprefix -L,$(dir $(LIBS)))
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf " $(DARK_BLUE) 🤔 Loading libft: $(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
	@if [ $(COUNT) -eq $(words $(SRCS)) ]; then \
		printf "$(GREEN)  🙂 Libft is ready!\n"; \
	fi
endef

# define comp_static_library
# 	printf "$(GREEN)  🙂 Libft is ready!\n$(RESET)"
# endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(NAME)
	$(call comp_static_library)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)
	$(AR) $(NAME) $@

$(NAME): $(OBJS)


clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)
