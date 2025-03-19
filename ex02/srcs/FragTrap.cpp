/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:29:33 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/19 15:24:02 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors and Destructor
FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    else if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " is already dead and cannot attack!" << std::endl;
        return;
    }
    else
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
                  << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

// Special ability
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}