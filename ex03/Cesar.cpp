/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"

Cesar::Cesar() :
_shift(3)
{}

static bool isAlpha(char c)
{
    if (('A' <= c && c <= 'Z')
    || ('a' <= c && c <= 'z'))
        return (true);
    return (false);
}

void Cesar::encryptChar(char plainchar)
{
    if (!isAlpha(plainchar)) {
        std::cout << plainchar;
        _shift += 1;
        return;
    }

    bool isUp = ('A' <= plainchar && plainchar <= 'Z' ? true : false);

    for (std::size_t ctr = 0; ctr < _shift; ctr += 1) {
        plainchar += 1;
        plainchar = (isUp ? (plainchar > 'Z' ? 'A' : plainchar)
                          : (plainchar > 'z' ? 'a' : plainchar));
    }
    _shift += 1;
    std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
    if (!isAlpha(cipherchar)) {
        std::cout << cipherchar;
        _shift += 1;
        return;
    }

    bool isUp = ('A' <= cipherchar && cipherchar <= 'Z' ? true : false);

    for (std::size_t ctr = 0; ctr < _shift; ctr += 1) {
        cipherchar -= 1;
        cipherchar = (isUp ? (cipherchar < 'A' ? 'Z' : cipherchar)
                           : (cipherchar < 'a' ? 'z' : cipherchar));
    }

    _shift += 1;
    std::cout << cipherchar;
}

void Cesar::reset()
{
    _shift = 3;
}