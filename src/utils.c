#include "../include/utils.h"

#include <stdlib.h>

int StringLength(char *str) {
    int count = 0;
    while(str[count]) ++count;
    return count+1;
}

#define NEWTONS_METHOD_ITERATIONS 25

float SquareRoot(float x) {
    float approx = x/2;
    // f(a) = a*a - x -> sqrt(x) is a root of this polynomial
    // f'(a) = 2a
    for (int i = 0; i < NEWTONS_METHOD_ITERATIONS; ++i) {
        approx = approx - ((approx*approx - x)/(2*approx));
    }
    return approx;
}

Memory Memory_From(void *src) {
    return (Memory) {src, 0};
}

const char *ReadString(Memory *memory) {
    byte *bytes = memory->src;
    char *str_src = &bytes[memory->offset];
    int len = StringLength(str_src);
    char *ret_str = malloc(len);
    for (int i = 0; i < len; ++i) {
        ret_str[i] = str_src[i];
    }
    memory->offset += len;
    return ret_str;
}
int ReadInt(Memory *memory) {
    byte *bytes = memory->src;
    int *ptr = &bytes[memory->offset];
    memory->offset += sizeof(int);
    return *ptr;
}
float ReadFloat(Memory *memory) {
    byte *bytes = memory->src;
    float *ptr = &bytes[memory->offset];
    memory->offset += sizeof(float);
    return *ptr;
}
byte ReadByte(Memory *memory) {
    byte *bytes = memory->src;
    byte b = bytes[memory->offset];
    ++memory->offset;
    return b;
}

void WriteString(Memory *memory, char *str) {
    int index = 0;
    while (str[index] != '\0') {
        WriteByte(memory, str[index]);
    }
    WriteByte(memory, '\0');
}
void WriteInt(Memory *memory, int i) {
    byte *bytes = memory->src;
    int *ptr = &bytes[memory->offset];
    *ptr = i;
    memory->offset += sizeof(int);
}
void WriteFloat(Memory *memory, float f) {
    byte *bytes = memory->src;
    float *ptr = &bytes[memory->offset];
    *ptr = f;
    memory->offset += sizeof(float);
}
void WriteByte(Memory *memory, byte b) {
    byte *bytes = memory->src;
    bytes[memory->offset] = b;
    ++memory->offset;
}