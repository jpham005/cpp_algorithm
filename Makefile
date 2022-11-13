.PHONY: all
all:
	c++ -std=c++11 -g -fsanitize=address -fsanitize=undefined -pedantic -Wall -Wextra -Werror $(SRCS)

.PHONY: clean
clean:
	rm -f a.out
