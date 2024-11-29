#ifndef _UTILS_H_
#define _UTILS_H_

//collection of utility functions and structs

//returns the length of this string, including the nullbyte
//if the string is mallced it must be free'd by the caller
int StringLength(char *str);

//square root algorithm that is not as exact but should be pretty fast
float SquareRoot(float x);

//typdef for a byte type
typedef char byte;

//struct for continiously reading/writing to memory
typedef struct {
    void *src;
    int offset;
} Memory;

//reads a string from this memory and advanced the offset
//string is malloced and has to be free'd by caller
//if there is no null terminated string at the current position UB occurs
const char *ReadString(Memory *memory);
//reads an int from this memory and advances the offset
int ReadInt(Memory *memory);
//reads a float from this memory and advances the offset
float ReadFloat(Memory *memory);
//reads a byte from this memory and advances the offset
byte ReadByte(Memory *memory);

//writes a string to this memory and advances the offset
//if the string is malloced it must be free'd by the caller
void WriteString(Memory *memory, char *str);
//writes an int to this memory and advances the offset
void WriteInt(Memory *memory, int i);
//writes a float to this memory and advances the offset
void WriteFloat(Memory *memory, float f);
//writes a byte to this memory and advances the offset
void WriteByte(Memory *memory, byte b);

#endif // _UTILS_H_