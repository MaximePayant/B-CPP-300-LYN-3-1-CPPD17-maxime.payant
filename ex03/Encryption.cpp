/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Encryption.cpp
*/

#include <iostream>
#include <functional>

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &encryptionMethod, void (IEncryptionMethod::*func)(char c)) :
_method(encryptionMethod),
_func(func)
{}

void Encryption::operator()(char c)
{
    (_method.*_func)(c);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, const std::string& toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), std::function<void(char)>([&](char c) { encryptionMethod.encryptChar(c); }));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& encryptionMethod, const std::string& toDecrypt)
{
    encryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), std::function<void(char)>([&](char c) { encryptionMethod.decryptChar(c); }));
    std::cout << std::endl;
}