.PHONY: all
all:
	c++ -g -fsanitize=address -fsanitize=undefined -Wall -Wextra -Werror $(SRCS)

.PHONY: clean
clean:
	rm -f a.out
