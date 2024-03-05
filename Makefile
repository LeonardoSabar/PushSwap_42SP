PUSH_SWAP	:= push_swap

CHECKER := checker

CC	:= cc
CFLAGS	:= -Wextra -Wall -Werror -g3

LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf

SRC	:= src/push_swap.c
OBJS	:= $(SRC:src/%.c=obj/%.o)

SRC_BONUS := bonus/checker.c
BONUS_OBJS := $(SRC_BONUS:bonus/%.c=obj_bonus/%.o)

.SILENT:

GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m

HEADERS	:= -I ./include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm

all: libft printf $(PUSH_SWAP)

bonus: libft printf $(SRC_BONUS)

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

$(PUSH_SWAP): $(OBJS)
	printf "\n$(YELLOW) Compiling push_swap...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(PUSH_SWAP)
	printf "\n$(GREEN) Done!\n $(RESET)"

$(SRC_BONUS): $(BONUS_OBJS)
	printf "\n$(YELLOW) Compiling checker bonus...$(RESET)\n"
	$(CC) $(CLIENT_BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_CLIENT)
	printf "\n$(GREEN) Done!\n $(RESET)"

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

obj_bonus/%.o: bonus/%.c
	mkdir -p obj_bonus
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf obj obj_bonus

fclean: clean
	rm -rf $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: all, clean, fclean, re, libft, printf
