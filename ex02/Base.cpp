/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
    {
        std::cout << "Generated: A" << "\n";
        return new A;
    }
    else if (r == 1)
    {
        std::cout << "Generated: B" << "\n";
        return new B;
    }
    else
    {
        std::cout << "Generated: C" << "\n";
        return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << "\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << "\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << "\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << "\n";
        return;
    }
    catch (std::exception&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << "\n";
        return;
    }
    catch (std::exception&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << "\n";
        return;
    }
    catch (std::exception&) {}
}