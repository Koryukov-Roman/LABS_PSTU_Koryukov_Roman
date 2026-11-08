#include <iostream>
#include <cstring>
#include <clocale>
#include <cwctype>
#include <cwchar>

using namespace std;

//todo является ли слово палиндромом
bool isPalindrom(const char* word) {
    wchar_t wword[256];

    mbstate_t state{};
    const char* src = word;

    //todo перевожу UTF-8 строку в широкие символы для корректного сравнения
    size_t wlen = mbsrtowcs(wword, &src, 256, &state);

    if (wlen == (size_t)-1 || wlen == 0 || wlen >= 256) {
        return false;
    }

    int start = 0;
    int end = wlen - 1;

    while (start < end) {
        //? сравниваю символы в нижнем регистре
        if (towlower(wword[start]) != towlower(wword[end])) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    if (setlocale(LC_ALL, "Russian") == NULL) {
        return 1;
    }

    char text[256];

    //! пишу слова латиницей, чтобы избежать любых проблем с кодировкой
    cout << "Enter string: " << endl;
    cin.getline(text, 256);

    cout << "\nPalindromes found: " << endl;

    char currentWord[256];
    int wordLen = 0;
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == ' ' || text[i] == '.') {
            if (wordLen > 0) {
                currentWord[wordLen] = '\0';

                if (isPalindrom(currentWord)) {
                    cout << currentWord << endl; 
                }

                wordLen = 0;
            }
        }
        else {
            currentWord[wordLen] = text[i];
            wordLen++;
        }
        i++;
    }

    if (wordLen > 0) {
        currentWord[wordLen] = '\0';
        if (isPalindrom(currentWord)) {
            cout << currentWord << endl;
        }
    }

    return 0;
}