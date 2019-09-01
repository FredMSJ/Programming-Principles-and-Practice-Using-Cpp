// Written by Jtaim
// 25 Mar 2017
// Header file used for Programming: Principles and Practice Using C++ Second Edition
// section 4

#ifndef SECTION4_H		// begin header guard
#define SECTION4_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <typeinfo>
#include <limits>
#include <ctime>
#include <numeric>
#include <random>

// simple function to keep window console open
inline void keep_window_open()
{
	std::cin.clear();
	std::cin.sync_with_stdio(false);
	std::cin.ignore(std::cin.rdbuf()->in_avail());  //clear buffer
	std::cout << "\nPress the Enter key to continue";
	std::cin.get();
}

// error function to be used (only) until error() is introduced in Chapter 5:
void simple_error(std::string s)	// write error: s and exit program
{
	std::cerr << "error: " << s << '\n';
	keep_window_open();
	std::exit(1);
}
#endif		// close header guard
