#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>


class Calculator
{
public:
    Calculator();
    std::vector<std::vector<int>> Parse_to_2x2(std::string arg);
    std::vector<std::vector<int>> Parse_to_3x3(std::string arg);
    std::string addition_to_plural(std::string arg);
    std::string complanation(std::string arg);
    std::string operations_wth_plurals(std::string arg);
    std::string orthogonality(std::string arg);
    std::string square_of_parallelegramm(std::string arg);
    std::string to_polar(std::string arg);
    std::string turn_point(std::string& arg);
    std::string volume_of_parallelepiped(std::string arg);
};

#endif // CALCULATOR_H
