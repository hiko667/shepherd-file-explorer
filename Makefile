all:
	gcc -I./src -I./src/filesystem ./src/*.c ./src/filesystem/*.c -o explorer.exe

run:
	./explorer.exe