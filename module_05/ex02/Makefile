# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auzun <auzun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 02:05:03 by auzun             #+#    #+#              #
#    Updated: 2023/02/18 16:57:42 by auzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compilation flags
ifeq ($(DMEM),1)
MEM 		= -fsanitize=address
endif

ifeq ($(DTHREAD),1)
MEM 		= -fsanitize=thread
endif

#==============================================================================#
#                                   TARGETS                                    #
#==============================================================================#

NAME = Bureaucrat

#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -MMD
MKDIR = mkdir -p
RM = rm -f
MAKE_SILENT = make --no-print-directory

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

PURPLE = \033[35m
GREEN = \033[32m
YELLOW = \033[33m
END = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src/
BONUS_SRC_DIR = bonus_src/
HEADER_DIR = include/
OBJ_DIR = obj/

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

#==============================================================================#
#                                   HEADERS                                    #
#==============================================================================#

HEAD_NAME = $(HEADER_DIR)/Bureaucrat.hpp $(HEADER_DIR)/AForm.hpp $(HEADER_DIR)/ShrubberyCreationForm.hpp \
			$(HEADER_DIR)/RobotomyRequestForm.hpp $(HEADER_DIR)/PresidentialPardonForm.hpp
INC = -I./$(HEADER_DIR)

#==============================================================================#
#                                   OBJECTS                                    #
#==============================================================================#

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.cpp=.o})

#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(HEAD_NAME)
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(DFLAGS) $(MEM) $(INC) -c $< -o $@ -g

$(NAME) : $(OBJ)
	echo "$(YELLOW)Making Bureaucrat$(END)"
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(MEM) -o $(NAME) -g
	echo "$(GREEN)Done$(END)"

clean :
	echo "$(PURPLE)Cleaning Bureaucrat's objects...$(END)"
	$(RM)r $(OBJ_DIR)
	echo "$(GREEN)Done$(END)"

fclean : clean
	echo "$(PURPLE)Cleaning Bureaucrat...$(END)"
	$(RM) $(NAME)
	echo "$(GREEN)Done$(END)"

re : fclean
	$(MAKE_SILENT) all

.PHONY : all clean fclean re
.SILENT :
