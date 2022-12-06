#pragma once

#include <iostream>

class String
{
private:
    char* c_buffer;
    size_t size;
public:
    String(const char* newString);
    ~String();

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    // String& operator=(const char* newChars);
};