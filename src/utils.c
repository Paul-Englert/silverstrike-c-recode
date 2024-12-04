#include "../include/utils.h"

#include <stdlib.h>
#include <stdio.h>

int StringLength(char *str) {
    int count = 0;
    while(str[count]) ++count;
    return count+1;
}

#define NEWTONS_METHOD_ITERATIONS 25

float SquareRoot(float x) {
    float approx = x/2;
    // f(a)  = a*a - x      -> sqrt(x) is a root of this polynomial
    // f'(a) = 2a
    for (int i = 0; i < NEWTONS_METHOD_ITERATIONS; ++i) {
        approx = approx - ((approx*approx - x)/(2*approx));
    }
    return approx;
}

#define STRING_BUFFER_INITIAL_CAP 10

static void StringBuffer_EnsureCap(StringBuffer *sb) {
    if (sb->len >= sb->capacity) {
        size_t new_cap = sb->capacity + STRING_BUFFER_INITIAL_CAP;
        sb->chars = realloc(sb->chars, new_cap * sizeof(char));
        sb->capacity = new_cap;
    }
}

char *StringBuffer_ToString(StringBuffer *sb) {
    char *str = malloc((sb->len+1)*sizeof(char));
    for (size_t i = 0; i < sb->len; ++i) {
        str[i] = sb->chars[i];   
    }
    str[sb->len] = '\0';
    return str;
}

void StringBuffer_Free(StringBuffer *sb) {
    free(sb->chars);
}

StringBuffer StringBuffer_New(void) {
    return (StringBuffer) {malloc(STRING_BUFFER_INITIAL_CAP * sizeof(char)), STRING_BUFFER_INITIAL_CAP, 0};
}

void StringBuffer_Clear(StringBuffer *sb) {
    sb->len = 0;
}

void StringBuffer_PushChar(StringBuffer *sb, char c) {
    ++sb->len;
    StringBuffer_EnsureCap(sb);
    sb->chars[sb->len-1] = c;
}

void StringBuffer_PushString(StringBuffer *sb, char *str) {
    size_t i = 0;
    while (str[i] != '\0') {
        StringBuffer_PushChar(sb, str[i]);
        ++i;
    }
}

