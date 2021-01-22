/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Encryption.hpp
*/

#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <algorithm>
#include <string>

#include "IEncryptionMethod.hpp"

class Encryption
{

    private:
        IEncryptionMethod &_method;
        void (IEncryptionMethod::*_func)(char c);

    public:
        Encryption(IEncryptionMethod &encryptionMethod, void (IEncryptionMethod::*func)(char c));

        void operator()(char c);

        static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod& encryptionMethod, const std::string &toDecrypt);

};

#endif // ENCRYPTION_HPP