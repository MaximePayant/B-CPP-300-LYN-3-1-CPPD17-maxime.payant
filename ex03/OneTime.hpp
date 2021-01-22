/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** OneTime.hpp
*/

#ifndef ONE_TIME_HPP
#define ONE_TIME_HPP

#include <iostream>

#include "IEncryptionMethod.hpp"

class OneTime :
    public IEncryptionMethod
{

    private:
        std::string _key;
        std::size_t _index;

    public:
        OneTime(const std::string& key);

        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

};

#endif // ONE_TIME_HPP