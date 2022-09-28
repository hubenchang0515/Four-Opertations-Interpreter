#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

inline bool is_char_in(char ch, const char* str)
{
    for (size_t i = 0; str[i] != 0; i++)
    {
        if (ch == str[i])
            return true;
    }

    return false;
}

inline bool is_int_in(int value, const int* array, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (value == array[i])
            return true;
    }

    return false;
}

#endif // UTILS_H