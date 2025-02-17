CC = gcc
EXEC = bin/OpenSDL2_V2
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

# Compilation
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 

obj/%.o: src/%.c
	$(CC) -c $< -o $@ -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

clean :
	for %%f in (obj\*.o)do del /F /Q "%%f"

cleanall : clean
	del /F /Q bin\OpenSDL2_V2.exe