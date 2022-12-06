WARNINGS := -fsanitize=address -Wall -Wextra -Wshadow

% : %.cpp
	g++ $(WARNINGS) -o $@.out $<
	./$@.out
