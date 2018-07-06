#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

int getInt(std::string, int, int);
int modifiedGetInt(std::string, int, int);
void printMenu(const std::vector<std::string> &);
void menu(int &, std::vector<std::string> &, std::string, std::string);

#endif

