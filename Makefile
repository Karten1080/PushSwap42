# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 19:04:34 by asmati            #+#    #+#              #
#    Updated: 2025/10/23 19:10:28 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

# Compilateur et flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(INCLUDE_DIR)

# Répertoires
LIBFT_DIR   = ./Bib/Libft
PRINTF_DIR  = ./Bib/PRINTF
SRC_DIR     = ./src
INCLUDE_DIR = ./includes

# Bibliothèques archives
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

# Fichiers source et objets
SRCS        = $(SRC_DIR)/push_swap.c \
		 $(SRC_DIR)/parsing/parcing.c \
		 $(SRC_DIR)/operations/rotate_fonction.c \
		 $(SRC_DIR)/algorithms/algo.c \
		 $(SRC_DIR)/algorithms/bytes.c \
		 $(SRC_DIR)/utils/utils.c \
		 $(SRC_DIR)/utils/free.c

OBJS        = $(SRCS:.c=.o)

# Flags de linkage (ordre: libft puis printf)
LDFLAGS     = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# Règle par défaut
all: $(NAME)

# Construire l'exécutable. Les bibliothèques sont dépendances order-only
# pour éviter le relink si seuls les .a ont été régénérés sans changement
# des .o.
$(NAME): $(OBJS) | $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

# Compilation des librairies si nécessaire
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Règle pour compiler les .o à partir des .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des objets
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
