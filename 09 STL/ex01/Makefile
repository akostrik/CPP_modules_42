NAME    = RPN
SRCS    = main.cpp RPN.cpp
OBJS    = $(addprefix ./objs/, $(SRCS:.cpp=.o))
FLAGS   = -std=c++98 -Wall -Wextra -Werror
CPP     = c++


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

./objs/%.o: %.cpp
	@mkdir ./objs/ 2> /dev/null || true
	$(CPP) -o $@ -c $<

clean:
	rm -f $(OBJS)
	@rmdir ./objs/ 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, debug