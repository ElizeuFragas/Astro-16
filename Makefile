main = ./src/main.cpp
keyboardActions = ./src/keyboardActions.cpp
drawing = ./src/drawing.cpp
drawing_lib = ./lib/drawing.o
keyboardActions_lib = ./lib/keyboardActions.o
libs = $(drawing_lib) $(keyboardActions_lib)
includes = ./includes

Astro-16:  $(main) $(libs) 
	g++ -o ./build/Astro-16 $(main) $(libs) -I$(includes) -lGLU -lglut -lGL
./lib/keyboardActions.o: $(keyboardActions)
	g++ -c -o $(keyboardActions_lib) $(keyboardActions) -I$(includes) -lglut -lGLU -lGL
./lib/drawing.o: $(drawing)
	g++ -c -o $(drawing_lib) $(drawing) -I$(includes) -lglut -lGLU -lGL
run: 
	./build/Astro-16
clean:
	rm -f ./build/Astro-16 ./lib/*.o
