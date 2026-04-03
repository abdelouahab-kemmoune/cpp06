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

bool ScalarConverter::isValidInt(const std::string& literal) {
    size_t i = 0;
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
    if (literal[literal.size() - 1] != 'f')
        return false;
    std::string base = literal.substr(0, literal.size() - 1);

    if (isValidInt(base))
        return true;

    if (isValidDouble(base))
        return true;

    return false;
}


ScalarConverter::Type ScalarConverter::detectType(const std::string& literal) {
    if (isPseudoLiteral(literal))
        return PSEUDO;

    if (isChar(literal))
        return CHAR;

    if (isValidFloat(literal))
        return FLOAT;

    if (isValidDouble(literal))
        return DOUBLE;

    if (isValidInt(literal))
        return INT;

    return INVALID;
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

void ScalarConverter::handleNumber(const std::string& literal) {
    std::string temp = literal;
    if (temp.empty())
        return ;
    if (temp[temp.size() - 1] == 'f')
        temp.erase(temp.size() - 1);
    char *end;
    double value = strtod(temp.c_str(), &end);

    //char
    if (value < 0 || value > 127 || std::isnan(value))
        std::cout << "char: impossible" << "\n";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << "\n";
    else
        std::cout << "char: " << static_cast<char>(value) << "\n";
    
    //int
    if (value < INT_MIN || value > INT_MAX || std::isnan(value))
        std::cout << "int: impossible" << "\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    //float
    float f = static_cast<float>(value);

    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout <<"f\n";

    
    //double
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "\n";
}

void ScalarConverter::handlePseudo(const std::string& literal) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (literal[literal.size() - 1] == 'f')
    {
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
    }
    else
    {
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    Type type = detectType(literal);

    if (type == CHAR)
    {
        handleChar(literal[0]);
    }
    else if (type == PSEUDO)
    {
        handlePseudo(literal);
    }
    else if (type == INT || type == FLOAT || type == DOUBLE)
    {
        handleNumber(literal);
    }
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}