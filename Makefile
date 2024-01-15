all: compile link
objects := $(wildcard *.o)

compile:
	g++ -I dependencies\GLFW\include -I dependencies\glew\include -c $(wildcard src/*.cpp) -D GLEW_STATIC

link:
	g++ $(wildcard *.o) -o main -L dependencies\GLFW\lib -L dependencies\glew\lib\Release\Win32  -lglew32 -lglfw3 -lopengl32 -lGdi32 