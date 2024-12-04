#ifndef _UTILS_H_
#define _UTILS_H_

#include <stddef.h>

//collection of utility functions and structs

//returns the length of this string, including the nullbyte
//if the string is mallced it must be free'd by the caller
int StringLength(char *str);

//square root algorithm that is not as exact but should be pretty fast
float SquareRoot(float x);

typedef struct {
    char *chars;
    size_t capacity;
    size_t len;
} StringBuffer;

//creates a string from this StringBuffer. The returned string is malloced and must be freed by the user
char *StringBuffer_ToString(StringBuffer *sb);

//frees this StringBuffer
void StringBuffer_Free(StringBuffer *sb);

//creates a new, empty StringBuffer
StringBuffer StringBuffer_New(void);

//clears this StringBuffer
void StringBuffer_Clear(StringBuffer *sb);

//pushes a char to this StringBuffer
void StringBuffer_PushChar(StringBuffer *sb, char c);

//pushes an entire string to this StringBuffer
void StringBuffer_PushString(StringBuffer *sb, char *str);

#endif // _UTILS_H_