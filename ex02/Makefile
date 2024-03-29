# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 01:13:48 by juwkim            #+#    #+#              #
#    Updated: 2023/08/25 05:17:33 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#    Define the compiler and flags                                             #
# ---------------------------------------------------------------------------- #

CXX             :=	c++
CXXFLAGS        =	-Wall -Wextra -Werror -pipe -std=c++98
CPPFLAGS        =	-I./
DEPFLAGS        =	-MMD -MP -MF $(DEP_DIR)/$*.d
LDFLAGS         =
LDLIBS          =

ifdef DEBUG
    CXXFLAGS      +=	-g -O0 -DDEBUG -march=native -fsanitize=address,undefined
else
    CXXFLAGS      +=	-O2 -DNDEBUG
endif

# ---------------------------------------------------------------------------- #
#    Define the libraries                                                      #
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#    Define the directories                                                    #
# ---------------------------------------------------------------------------- #

PROJECT_DIR     :=	.

SRC_DIR         :=	$(PROJECT_DIR)
BUILD_DIR       :=	$(PROJECT_DIR)/build
OBJ_DIR         :=	$(BUILD_DIR)/object
DEP_DIR         :=	$(BUILD_DIR)/dependency

# ---------------------------------------------------------------------------- #
#    Define the source files                                                   #
# ---------------------------------------------------------------------------- #

SRCS            :=	$(shell find $(SRC_DIR) -name "*".cpp)
OBJS            :=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS            :=	$(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(SRCS))

# ---------------------------------------------------------------------------- #
#    Define the variables for progress bar                                     #
# ---------------------------------------------------------------------------- #

TOTAL_FILES     :=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES  :=	0

# ---------------------------------------------------------------------------- #
#    Define the target                                                         #
# ---------------------------------------------------------------------------- #

NAME            :=	ex02

# ---------------------------------------------------------------------------- #
#    Define the rules                                                          #
# ---------------------------------------------------------------------------- #

all:
	@ $(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@ printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(WHITE)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | dir_guard
	@ $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@
	@ $(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@ $(eval PROGRESS = $(shell expr 100 "*" $(COMPILED_FILES) / $(TOTAL_FILES)))
	@ printf "                                                                                                         \r"
	@ printf "$(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(WHITE)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

clean:
	@ $(RM) -r $(BUILD_DIR)
	@ printf "$(BLUE)[$(NAME)] obj. dep. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"

fclean: clean
	@ $(RM) -r $(BUILD_DIR) $(NAME)
	@ printf "$(BLUE)[$(NAME)] obj. dep. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"
	@ printf "$(CYAN)[$(NAME)] exec. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"

re: fclean
	@ $(MAKE) all
	@ printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(WHITE)"

dir_guard:
	@ mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@ mkdir -p $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(shell find $(SRC_DIR) -type d))
	@ mkdir -p $(patsubst $(SRC_DIR)/%, $(DEP_DIR)/%, $(shell find $(SRC_DIR) -type d))

debug: fclean
	@ $(MAKE) all DEBUG=1

test:
	@ ./$(NAME)

.PHONY: all clean fclean re dir_guard debug test

# ---------------------------------------------------------------------------- #
#    Define the colors                                                         #
# ---------------------------------------------------------------------------- #

GRAY            =	\033[1;90m
RED             =	\033[1;91m
GREEN           =	\033[1;92m
YELLOW          =	\033[1;93m
BLUE            =	\033[1;94m
MAGENTA         =	\033[1;95m
CYAN            =	\033[1;96m
WHITE           =	\033[1;97m

-include $(DEPS)
