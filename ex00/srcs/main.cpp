/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:20:01 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/16 20:21:28 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // Create ClapTrap instances
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("FR4G-TP");

    // Test basic functionality
    clap1.attack("Bandit");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    // Test copy constructor
    ClapTrap clap3(clap1);
    std::cout << "Clap3 name: " << clap3.getName() << std::endl;

    // Test energy depletion
    std::cout << "\nTesting energy depletion:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Energy left: " << clap1.getEnergyPoints() << " - ";
        clap1.attack("Target Dummy");
    }

    // Test taking fatal damage
    std::cout << "\nTesting fatal damage:" << std::endl;
    clap2.takeDamage(15);
    clap2.attack("Bandit"); // Should not work
    clap2.beRepaired(5);    // Should not work

    return 0;
}