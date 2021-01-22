/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Container.hpp
*/

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <algorithm>
#include <functional>
#include <iostream>

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
class contain
{

    private:
        Container<Contained> _container;

    public:
        contain();
        ~contain();

        void push(Contained const &data);
        void aff();
        void add();

        void aff(Contained b);
        void add(Contained& b);

};

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
contain<Contained, Container>::contain() :
_container()
{}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
contain<Contained, Container>::~contain()
{
    _container.clear();
}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
void contain<Contained, Container>::push(Contained const &data)
{
    _container.push_back(data);
}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
void contain<Contained, Container>::aff()
{
    std::for_each(_container.begin(), _container.end(), std::function<void(Contained)>([&](Contained v) { aff(v); }));
}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
void contain<Contained, Container>::add()
{
    std::for_each(_container.begin(), _container.end(), std::function<void(Contained&)>([&](Contained& v) { add(v); }));
}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
void contain<Contained, Container>::aff(Contained b)
{
    std::cout << "Value: " << b << std::endl;
}

template <typename Contained, template<class, class = std::allocator<Contained>> class Container>
void contain<Contained, Container>::add(Contained& b)
{
    b += 1;
}

#endif // CONTAINER_HPP