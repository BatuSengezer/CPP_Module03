/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:46:10 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/19 15:31:35 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    // Test FragTrap constructors and basic functionality
    std::cout << "Creating FragTrap objects:" << std::endl;
    FragTrap frag1("FRAG-1");
    FragTrap frag2("FRAG-2");

    // Test attack functionality
    std::cout << "\nTesting attack functionality:" << std::endl;
    frag1.attack("Enemy");
    frag2.attack("Enemy");

    // Test taking damage and repairing
    std::cout << "\nTesting taking damage and repairing functionality:" << std::endl;
    frag1.takeDamage(30);
    frag1.beRepaired(5);  // Should repair up to 100
    frag1.takeDamage(80); // Test taking more damage than current hit points

    // Test special ability
    std::cout << "\nTesting special ability:" << std::endl;
    frag1.highFivesGuys();

    // Test copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    FragTrap frag3(frag1);
    std::cout << "Frag3 name: " << frag3.getName() << std::endl;

    // Test assignment operator
    std::cout << "\nTesting assignment operator:" << std::endl;
    frag3 = frag2;
    std::cout << "After assignment, Frag3 name: " << frag3.getName() << std::endl;

    // Test inheritance relationship
    std::cout << "\nTesting inheritance relationship:" << std::endl;
    ClapTrap *clap = &frag1;
    clap->attack("Target");

    // Test energy depletion
    std::cout << "\nTesting energy depletion:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (frag2.getEnergyPoints() > 0 && frag2.getHitPoints() > 0)
        {
            std::cout << "Energy left: " << frag2.getEnergyPoints() << " - ";
            frag2.attack("Target");
        }
        else
        {
            std::cout << frag2.getName() << "is unable to attack due to lack of energy or being destroyed." << std::endl;
            break;
        }
    }

    // Test destruction order
    std::cout << "\nTesting destruction order:" << std::endl;
    {
        FragTrap tempFrag("TEMP-FRAG");
    } // tempFrag goes out of scope here

    return 0;
}