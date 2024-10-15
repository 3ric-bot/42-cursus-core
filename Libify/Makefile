.DEFAULT_GOAL := a

# Utility source files including logo
UTILS = $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
PARENT_DIR = $(shell dirname $(shell pwd))
LIBFT_PATH = $(PARENT_DIR)
TESTS_PATH = tests/

# Mandatory and Bonus functions
MANDATORY = memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
            isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
            atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
            putendl_fd putnbr_fd striteri
BONUS = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap

VSOPEN = $(addprefix vs, $(MANDATORY)) $(addprefix vs, $(BONUS))

CC = clang++
CFLAGS = -g3 -ldl -gdwarf-4 -std=c++11 -I utils/ -I$(LIBFT_PATH)/include -I$(PARENT_DIR)/include

# Ensure the Valgrind is set for Linux
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
    VALGRIND = valgrind -q --leak-check=full
endif
ifeq ($(IN_DOCKER),TRUE)
    LIBFT_PATH = /project/
endif

# Rule to display the logo
display_logo: 
	@echo " /--       /------ /-------  /------ /-------- /--     /--"
	@echo "| --      |_  --_/| --__  --|_  --_/| --_____/|  --   /--/"
	@echo "| --        | --  | --  \ --  | --  | --       \  -- /--/ "
	@echo "| --        | --  | -------   | --  | -----     \  ----/  "
	@echo "| --        | --  | --__  --  | --  | --__/      \  --/   "
	@echo "| --        | --  | --  \ --  | --  | --          | --    "
	@echo "| -------- /------| -------/ /------| --          | --    "
	@echo "|________/|______/|_______/ |______/|__/          |__/    "
	@echo ""

# Rule for mandatory tests with automatic error detection
$(MANDATORY): %: mandatory_start display_logo
	@echo "Running test for function: $*"
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L$(LIBFT_PATH) -lft -o a.out 2> compile_error.log
	@if [ $$? -ne 0 ]; then \
		if grep -q "undefined reference" compile_error.log; then \
			echo "Compilation error: Undefined reference in ft_$*_test.cpp"; \
		elif grep -q "fatal error: '.*.h' file not found" compile_error.log; then \
			echo "Compilation error: Missing header file in ft_$*_test.cpp"; \
		else \
			echo "Compilation error in ft_$*_test.cpp"; \
		fi; \
		cat compile_error.log; \
		rm -f compile_error.log; \
		exit 1; \
	fi
	@rm -f compile_error.log

	@$(VALGRIND) ./a.out 2> runtime_error.log
	@if [ $$? -ne 0 ]; then \
		if grep -q "Invalid read" runtime_error.log; then \
			echo "Runtime error: Invalid memory access detected in ft_$*_test"; \
		elif grep -q "Invalid write" runtime_error.log; then \
			echo "Runtime error: Invalid memory write detected in ft_$*_test"; \
		elif grep -q "definitely lost" runtime_error.log; then \
			echo "Memory leak detected in ft_$*_test"; \
		elif grep -q "Conditional jump or move" runtime_error.log; then \
			echo "Uninitialized variable used in ft_$*_test"; \
		else \
			echo "Runtime error in ft_$*_test"; \
		fi; \
		cat runtime_error.log; \
		rm -f runtime_error.log; \
		exit 1; \
	fi

	@echo "No errors found for function: $*"
	@echo "|--------------------------------------------------------|"
	@echo ""
	@rm -f a.out runtime_error.log

# Rule for bonus tests with automatic error detection
$(BONUS): %: bonus_start display_logo
	@echo "Running bonus test for function: $*"
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L$(LIBFT_PATH) -lft -o a.out 2> compile_error.log
	@if [ $$? -ne 0 ]; then \
		if grep -q "undefined reference" compile_error.log; then \
			echo "Compilation error: Undefined reference in ft_$*_test.cpp"; \
		elif grep -q "fatal error: '.*.h' file not found" compile_error.log; then \
			echo "Compilation error: Missing header file in ft_$*_test.cpp"; \
		else \
			echo "Compilation error in ft_$*_test.cpp"; \
		fi; \
		cat compile_error.log; \
		rm -f compile_error.log; \
		exit 1; \
	fi
	@rm -f compile_error.log

	@$(VALGRIND) ./a.out 2> runtime_error.log
	@if [ $$? -ne 0 ]; then \
		if grep -q "Invalid read" runtime_error.log; then \
			echo "Runtime error: Invalid memory access detected in ft_$*_test"; \
		elif grep -q "Invalid write" runtime_error.log; then \
			echo "Runtime error: Invalid memory write detected in ft_$*_test"; \
		elif grep -q "definitely lost" runtime_error.log; then \
			echo "Memory leak detected in ft_$*_test"; \
		elif grep -q "Conditional jump or move" runtime_error.log; then \
			echo "Uninitialized variable used in ft_$*_test"; \
		else \
			echo "Runtime error in ft_$*_test"; \
		fi; \
		cat runtime_error.log; \
		rm -f runtime_error.log; \
		exit 1; \
	fi

	@echo "No errors found for bonus function: $*"
	@echo "|--------------------------------------------------------|"
	@echo ""
	@rm -f a.out runtime_error.log


# Additional rules remain unchanged
mandatory_start: update message
	@tput setaf 93
	make -C $(LIBFT_PATH)
	@tput setaf 93 && echo [Mandatory]

bonus_start: update message
	@tput setaf 38
	@if grep -q 'bonus:' $(LIBFT_PATH)/Makefile; then \
		make bonus -C $(LIBFT_PATH); \
	else \
		tput setaf 1 && echo "Bonus target not found in $(LIBFT_PATH)/Makefile."; \
	fi
	@tput setaf 38 && echo [Bonus]

update:
	@git pull

message: checkmakefile
	@tput setaf 3 && echo "If all your tests are OK and the moulinette KO you, please run the tester with valgrind (see README)"

checkmakefile:
	@ls $(LIBFT_PATH) | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

# Docker rules remain unchanged
$(addprefix docker, $(MANDATORY)) $(addprefix docker, $(BONUS)) dockerm dockera: docker%:
	@docker rm -f mc > /dev/null 2>&1 || true
	docker build -qt mi .
	docker run -e IN_DOCKER=TRUE -dti --name mc -v $(LIBFT_PATH):/project/ -v $(PARENT_DIR)/libftTester:/project/libftTester mi
	docker exec -ti mc make $* -C libftTester || true
	@docker rm -f mc > /dev/null 2>&1

m: $(MANDATORY)
b: $(BONUS)
a: m b 

clean:
	make clean -C $(LIBFT_PATH) && rm -rf a.out*

fclean:
	make fclean -C $(LIBFT_PATH) && rm -rf a.out*

.PHONY: mandatory_start m bonus_start b a fclean clean update message $(VSOPEN) $(MAIL)
