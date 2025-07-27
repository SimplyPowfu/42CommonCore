/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:20:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 20:50:56 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Func.hpp"

Base *generate(void) {
    Base *result;

    switch (std::rand() % 3) {
        case (0):
            std::cout << "New A pointer" << std::endl;
            return new A();
        case (1):
            std::cout << "New B pointer" << std::endl;
            return new B();
        case (2):
            std::cout << "New C pointer" << std::endl;
            return new C();
        default:
            std::cout << "new A pointer" << std::endl;
            return new A();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer is A (" << p << ")" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer is B (" << p << ")" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer is C (" << p << ")" << std::endl;
    else
        std::cout << "Unknown pointer (" << p << ")" << std::endl;
}

void identify(Base &p) {
    try {
        A &result = dynamic_cast<A &>(p);
        std::cout << "Pointer is A (" << &result << ")" << std::endl;
        return;
    } catch (...) {
    }
    try {
        B &result = dynamic_cast<B &>(p);
        std::cout << "Pointer is B (" << &result << ")" << std::endl;
        return;
    } catch (...) {
    }
    try {
        C &result = dynamic_cast<C &>(p);
        std::cout << "Pointer is C (" << &result << ")" << std::endl;
        return;
    } catch (...) {
    }
    std::cout << "Pointer is unknown" << std::endl;
}