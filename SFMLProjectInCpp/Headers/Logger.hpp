#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <SFML/Graphics.hpp>

template<typename T>
inline void Logger(const T& l)
{
	std::cout << l << std::endl;
}


inline void LoggerEx(const std::exception& ex)
{
	std::cerr << "exception: " << ex.what() << std::endl;
}

template<typename T1, typename T2>
inline void Logger(const T1& l1, const T2& l2)
{
	std::cout << l1 << l2 << std::endl;
}

template<typename T1, typename T2, typename T3>
inline void Logger(const T1& l1, const T2& l2, const T3& l3)
{
	std::cout << l1 << " " << l2 << " " << l3 << std::endl;
}

#endif // EVENTS_H