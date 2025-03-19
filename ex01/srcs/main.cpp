/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:46:10 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/19 11:46:11 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // Test ScavTrap constructors and basic functionality
    ScavTrap scav1("SCAV-1");
    ScavTrap scav2("SCAV-2");

    // Test attacks and damage
    scav1.attack("Enemy");
    scav2.takeDamage(30);
    scav2.beRepaired(20);

    // Test guard gate function
    scav1.guardGate();

    // Test copy constructor
    ScavTrap scav3(scav1);
    std::cout << "Scav3 name: " << scav3.getName() << std::endl;

    // Test inheritance relationship
    ClapTrap *clap = &scav1;
    clap->attack("Target");

    // Test energy depletion
    std::cout << "\nTesting energy depletion:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Energy left: " << scav1.getEnergyPoints() << " - ";
        scav1.attack("Target");
    }

    return 0;
}