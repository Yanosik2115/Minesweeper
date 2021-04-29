LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX := g++ -Wall

all: thegame

%.o: %.cpp
	$(CXX) -c $< -o $@

%.o: %.hpp
	$(CXX) -c $< -o $@

thegame: main.o minesClass.o MSBoardTextView.o MSSFMLView.o MSTextController.o
	@echo "** Building the game"
	$(CXX) -o thegame main.o minesClass.o MSBoardTextView.o MSSFMLView.o MSTextController.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame *.o

install:
	@echo '** Installing...'
	cp thegame /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/thegame