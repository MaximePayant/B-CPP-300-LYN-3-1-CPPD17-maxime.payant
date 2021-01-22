/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** OneTime.cpp
*/

#include "OneTime.hpp"

static bool isAlpha(char c)
{
    if (('A' <= c && c <= 'Z')
    || ('a' <= c && c <= 'z'))
        return (true);
    return (false);
}

OneTime::OneTime(const std::string& key) :
_key(key)
{}

void OneTime::encryptChar(char plainchar)
{
    if (!isAlpha(plainchar)) {
        std::cout << plainchar;
        _index += 1;
        _index = (_index >= _key.size() ? 0 : _index);
        return;
    }

    bool isUp = ('A' <= _key[_index] && _key[_index] <= 'Z');
    bool cIsUp = ('A' <= plainchar && plainchar <= 'Z');

    for (int ctr = 0; ctr < _key[_index] - (isUp ? 'A': 'a'); ctr += 1) {
        plainchar += 1;
        plainchar = (cIsUp ? (plainchar > 'Z' ? 'A' : plainchar)
                          : (plainchar > 'z' ? 'a' : plainchar));
    }
    _index += 1;
    _index = (_index >= _key.size() ? 0 : _index);
    std::cout << plainchar;
}

void OneTime::decryptChar(char cipherchar)
{
    if (!isAlpha(cipherchar)) {
        std::cout << cipherchar;
        _index += 1;
        _index = (_index >= _key.size() ? 0 : _index);
        return;
    }

    bool isUp = ('A' <= _key[_index] && _key[_index] <= 'Z');
    bool cIsUp = ('A' <= cipherchar && cipherchar <= 'Z');

    for (int ctr = 0; ctr <  _key[_index] - (isUp ? 'A': 'a'); ctr += 1) {
        cipherchar -= 1;
        cipherchar = (cIsUp ? (cipherchar < 'A' ? 'Z' : cipherchar)
                           : (cipherchar < 'a' ? 'z' : cipherchar));
    }

    _index += 1;
    _index = (_index >= _key.size() ? 0 : _index);
    std::cout << cipherchar;
}

void OneTime::reset()
{
    _index = 0;
}