/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &literal) {
    return (literal.length() == 1 && !isdigit(literal[0]));
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf" || literal == "nan");
}

void ScalarConverter::handleChar(char c) {
    if (c >= 32 && c <= 126)
        std::cout << "char: " << c << '\n';
    else
        std::cout << "char: Non displayable" << "\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << "\n";
    std::cout << "double: " << static_cast<double>(c) << "\n"; 
}

bool ScalarConverter::isValidInt(const std::string& literal) {
    int i = 0;
    if (literal.empty())
        return false;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.size() == 1)
            return false;
        i = 1;
    }
    for (;i < literal.size(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isValidDouble(const std::string& literal) {
    size_t i = 0;
    int dotCount = 0;
    bool hasDigit = false;

    if (literal.empty())
        return false;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.size() == 1)
            return false;
        i = 1;
    }
    for (; i < literal.size(); i++)
    {
        if (std::isdigit(literal[i]))
            hasDigit = true;
        else if (literal[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else
            return false;
    }
    if (dotCount != 1)
        return false;
    if (!hasDigit)
        return false;
    return true;
}

bool ScalarConverter::isValidFloat(const std::string& literal) {
    if (literal.size() < 2)
        return false;
    if (literal[literal.length() - 1] == 'f')
        return false;
    
}




// ScalarConverter::Type ScalarConverter::detectType(const std::string& literal) {
//     int i;
//     while (i = 0)
//     if (isPseudoLiteral(literal))
//         return PSEUDO;
//     if (isChar(literal))
//         return CHAR;
//     if (literal[literal.size() - 1] == 'f')
//         if (isdigit(literal[i]))
//             return FLOAT;
//         else
//             std::cout << "invalid" << "\n";
//     if (literal.find('.') != std::string::npos)
//         return DOUBLE;
//     if (literal)
// }
