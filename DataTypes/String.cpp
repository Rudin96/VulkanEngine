#include "String.h"
#include <cstring>

String::String(const char* newString)
{
    size = strlen(newString);
    c_buffer = new char[size + 1];
    memcpy(c_buffer, newString, size);
    c_buffer[size] = 0;
}

String::~String()
{
    delete[] c_buffer;
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.c_buffer << std::endl;
    return stream;
}