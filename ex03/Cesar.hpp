/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Cesar.hpp
*/

#ifndef CESAR_HPP
#define CESAR_HPP

#include <iostream>

#include "IEncryptionMethod.hpp"

class Cesar :
    public IEncryptionMethod
{

    private:
        std::size_t _shift;

    public:
        Cesar();

        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

};

#endif // CESAR_HPP