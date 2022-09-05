
#pragma once

#include <memory>
#include "Location.h"
#include <unordered_map>

// A template class that implement factory for creating game objects.

template <typename T>
class Factory {
public:

    using pFnc = std::unique_ptr<T>(*)(const Location &);

    static std::unique_ptr<T> create(const char &, const Location &);

    static bool registerObject(const char &, pFnc);

private:
    static auto & getMap(){
        static std::unordered_map<char, pFnc> map;
        return map;
    }
};
//=============================================================================
template <typename T>
std::unique_ptr<T> Factory<T>::create(const char & pieceType, const Location & pos) {

    // Checks if the request object is registered to the factory.
    auto it = Factory::getMap().find(pieceType);
    if(it == Factory::getMap().end())
        throw std::invalid_argument("No such piece");
    return it->second(pos);
}
//=============================================================================
template <typename T>
bool Factory<T>::registerObject(const char & pieceType, Factory::pFnc func) {
    // Registers object to the factory.
    Factory::getMap().emplace(pieceType, func);

    return true;
}
//=============================================================================