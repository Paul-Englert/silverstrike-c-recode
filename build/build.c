#include <stdio.h>

int main(int arg_c, char **args) {
    system("gcc ../src/main.c -c -Wall -o objects/main.o");
    system("gcc ../src/vec2.c -c -Wall -o objects/vec2.o");
    system("gcc ../src/gui.c -c -Wall -o objects/gui.o");
    system("gcc ../src/utils.c -c -Wall -o objects/utils.o");
    system("gcc objects/main.o objects/vec2.o objects/gui.o objects/utils.o -o out/silverstriker.exe -L../libs -l:libraylib.a -lopengl32 -lgdi32 -lwinmm");
    return 0;
}