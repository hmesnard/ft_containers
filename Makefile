CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -D STL=${STL} -D VERSION=${VERSION}
SRCS	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

NAME	= tests


all		:	$(NAME)

$(NAME)	:	$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
help	:	
			@echo "Specify STL=1 for the STL version and STL=0 for my containers,\nand specify VERSION=0/1/2 for my main, the performance main, the subject main and the complete cplusplus function test respectively"

diff	:
			make re STL=0 VERSION=${V}
			./tests > mine
			make re STL=1 VERSION=${V}
			./tests > original
			make fclean
			diff mine original

clean:
				rm -rf $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

.PHONY:		all fclean re
