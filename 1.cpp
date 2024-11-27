#include <iostream>
#include <cstring>

// Создает копию строки |str|.
char* CopyString(const char* str) {
    int len = 0;
    while (*(str + len) != '\0') {
        len++;
    }
    char* new_str = new char[len + 1];
    std::memcpy(new_str, str, len + 1);
    return new_str;
}

// Соединяет две строки в одну новую.
char* ConcatinateStrings(const char* a, const char* b) {
    int len1 = 0, len2 = 0;
    while (*(a + len1) != '\0') {
        len1++;
    }
    while (*(b + len2) != '\0') {
        len2++;
    }
    char* new_str = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; ++i) {
        new_str[i] = a[i];
    }
    for (int i = 0; i < len2; ++i) {
        new_str[len1 + i] = b[i];
    }
    new_str[len1 + len2] = '\0';
    return new_str;
}

int main()
{
    char a[] = { 'q','w','e','r','t','y','\0' };
    char b[] = { 'q','w','e','r','t','y','\0' };
    char* str = a;

    char* newstr1 = CopyString(str);
    std::cout << newstr1 << std::endl;

    char* newstr2 = ConcatinateStrings(a, b);
    std::cout << newstr2;
}
