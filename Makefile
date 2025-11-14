# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2025/07/08 21:13:23 by mahkilic      #+#    #+#                  #
#    Updated: 2025/11/14 19:14:49 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -Iinclude

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = include

# Source files and object files
SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/check/check_args.c \
		$(SRCDIR)/check/check_philos.c \
		$(SRCDIR)/init/init_forks.c \
		$(SRCDIR)/init/init_input.c \
		$(SRCDIR)/init/init_philos.c \
		$(SRCDIR)/init/init_program.c \
		$(SRCDIR)/init/init_threads.c \
		$(SRCDIR)/routine/eating.c \
		$(SRCDIR)/routine/sleeping.c \
		$(SRCDIR)/routine/thinking.c \
		$(SRCDIR)/routine/routine.c \
		$(SRCDIR)/utils/ft_atoi.c \
		$(SRCDIR)/utils/ft_destroy.c \
		$(SRCDIR)/utils/ft_gettimeofday.c \
		$(SRCDIR)/utils/ft_print_msg.c \
		$(SRCDIR)/utils/ft_strlen.c \
		$(SRCDIR)/utils/ft_usleep.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
NAME = philo

# Colors for output
GREEN		=	\033[0;32m
ORANGE	=	\033[38;5;214m
GRAY		=	\033[0;90m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GRAY)Building philo..."
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -o $(NAME) -pthread
	@echo "$(GREEN)$(NAME) has been created successfully."

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@echo "$(ORANGE)Cleaning object files..."
	@rm -rf $(OBJDIR)
	@echo "$(ORANGE)Objects have been removed."

fclean: clean
	@echo "$(ORANGE)Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(ORANGE)$(NAME) has been removed."

re: fclean all

.PHONY: all clean fclean re