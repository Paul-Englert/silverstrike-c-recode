#ifndef _UTILS_H_
#define _UTILS_H_

//collection of utility functions and structs

//returns the length of this string, including the nullbyte
//if the string is mallced it must be free'd by the caller
int StringLength(char *str);

//square root algorithm that is not as exact but should be pretty fast
float SquareRoot(float x);

#endif // _UTILS_H_