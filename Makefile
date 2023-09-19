main = ./src/main.cpp
actions = ./src/actions.cpp
drawing = ./src/drawing.cpp
window = ./src/window.cpp
utils = ./src/utils.cpp
drawing_lib = ./lib/drawing.o
actions_lib = ./lib/actions.o
window_lib = ./lib/window.o
utils_lib = ./lib/utils.o
libs = $(drawing_lib) $(window_lib) $(actions_lib) $(utils_lib)
includes = ./includes

Astro-16:  $(main) $(libs) 
	g++ -o ./build/Astro-16 $(main) $(libs) -I$(includes) -lGLU -lglut -lGL
./lib/actions.o: $(actions)
	g++ -c -o $(actions_lib) $(actions) -I$(includes) -lglut -lGLU -lGL
./lib/drawing.o: $(drawing)
	clear
	g++ -c -o $(drawing_lib) $(drawing) -I$(includes) -lglut -lGLU -lGL
./lib/window.o: $(window)
	g++ -c -o $(window_lib) $(window) -I$(includes) -lglut -lGLU -lGL
./lib/utils.o: $(utils)
	g++ -c -o $(utils_lib) $(utils) -I$(includes) -lglut -lGLU -lGL
animation: 
	g++ -o a ./test/test3.cpp $(libs) -I$(includes) -lglut -lGLU -lGL
	./a
	
run: 
	./build/Astro-16
copy:
	cp ./includes/* ./src/*.cpp ../pj/Project1/
clean:
	rm -f ./build/Astro-16 ./lib/*.o
