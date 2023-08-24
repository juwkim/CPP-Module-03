/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 05:52:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:44:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:ClapTrap("juwon", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << '\n';
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << getName() << " destructor called" << '\n';
}


ScavTrap::ScavTrap(const std::string& name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << getName() << " constructor called" << '\n';
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
	:ClapTrap(scavTrap.getName())
{
	std::cout << "ScavTrap copy constructor called" << '\n';
	setName(scavTrap.getName());
	setHitPoints(scavTrap.getHitPoints());
	setEnergyPoints(scavTrap.getEnergyPoints());
	setAttackDamage(scavTrap.getAttackDamage());
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "ScavTrap copy assignment operator called" << '\n';
	setName(scavTrap.getName());
	setHitPoints(scavTrap.getHitPoints());
	setEnergyPoints(scavTrap.getEnergyPoints());
	setAttackDamage(scavTrap.getAttackDamage());
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " cannot attack" << '\n';
		return;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << '\n';
	setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate(void)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " cannot guard a gate" << '\n';
		return;
	}
	std::cout << "ScavTrap " << getName() 
		<< " is now in Gate keeper mode" << '\n';
}
