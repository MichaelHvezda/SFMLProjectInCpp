#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <SFML/Graphics.hpp>

template<typename T>
inline void Logger(T& l)
{
	std::cout << l << std::endl;
}


inline void LoggerEx(std::exception& ex)
{
	std::cerr << "exception: " << ex.what() << std::endl;
}

template<typename T1, typename T2>
inline void Logger(T1& l1, T2& l2)
{
	std::cout << l1 << l2 << std::endl;
}

template<typename T1, typename T2, typename T3>
inline void Logger(T1& l1, T2& l2, T3& l3)
{
	std::cout << l1 << " " << l2 << " " << l3 << std::endl;
}

#endif // EVENTS_H