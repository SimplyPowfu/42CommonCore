/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 13:42:23 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    std::cout << "=== Sezione 1: Inserimento iniziale ===" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top after pushes: " << mstack.top() << std::endl;

    std::cout << "\n=== Sezione 2: Pop e dimensione ===" << std::endl;
    mstack.pop();  // rimuove 17
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    std::cout << "\n=== Sezione 3: Aggiunta di altri elementi ===" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Elements added: 3, 5, 737, 0" << std::endl;

    std::cout << "\n=== Sezione 4: Iterazione con iteratori ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Contents traversing from begin to end:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    return (0);
}
