/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:15:08 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/19 11:22:33 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Orthodox Canonical Form
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap name constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    else if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot attack!" << std::endl;
        return;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                  << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot take more damage!" << std::endl;
        return;
    }
    else if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!" << std::endl;
        return;
    }
    else if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired!" << std::endl;
        return;
    }
    else
    {
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount
                  << " hit points! Current hit points: " << _hitPoints << std::endl;
        _energyPoints--;
    }
}

// Getters
std::string ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}