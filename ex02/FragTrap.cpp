/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 06:35:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:50:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	:ClapTrap("juwon", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << '\n';
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " destructor called" << '\n';
}


FragTrap::FragTrap(const std::string& name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << getName() << " constructor called" << '\n';
}

FragTrap::FragTrap(const FragTrap& fragTrap)
	: ClapTrap(fragTrap.getName(),
		fragTrap.getHitPoints(),
		fragTrap.getEnergyPoints(),
		fragTrap.getAttackDamage())
{
	std::cout << "FragTrap copy constructor called" << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << "FragTrap copy assignment operator called" << '\n';
	setName(fragTrap.getName());
	setHitPoints(fragTrap.getHitPoints());
	setEnergyPoints(fragTrap.getEnergyPoints());
	setAttackDamage(fragTrap.getAttackDamage());
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0) {
		std::cout << "FragTrap " << getName() << " cannot high-fives" << '\n';
		return;
	}
	std::cout << "FragTrap high-fives!" << '\n';
}
