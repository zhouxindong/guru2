#pragma once

#include <type_traits>

/**
 * 1. type
 typename std::trait<...>::type
 std::trait_t<...>

 * 2. value
 std::trait<...>::value
 std::trait<...>() // implicit conversion to its type
 std::trait_v<>
 */