/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <climits>
#include <cctype>
#include <string>
#include <cmath>
#include <iomanip>

class ScalarConverter {
private:
    ScalarConverter();

public:
    static void convert(const std::string& literal);

private:
    enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };
    static Type detectType(const std::string& literal);

    static void handleChar(char c);
    static void handleNumber(const std::string& literal);
    static void handlePseudo(const std::string& literal);

    
    // checking
    static bool isChar(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);
    static bool isValidInt(const std::string& literal);
    static bool isValidDouble(const std::string& literal);
    static bool isValidFloat(const std::string& literal);
};

# endif