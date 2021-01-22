/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** find.cpp
*/

#ifndef FIND_HPP
#define FIND_HPP

#include <algorithm>
#include <iterator>

template <class T>
typename T::iterator do_find(const T& list, int toFind)
{
    return (std::find(list.begin(), list.end(), toFind));
}

#endif // FIND_HPP