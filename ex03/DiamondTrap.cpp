/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 06:57:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 10:46:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ScavTrap(),
	FragTrap(),
	mName("juwon")
{
	ClapTrap::setName("_clap_name");
	std::cout << "DiamondTrap default constructor called" << '\n';
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << mName << " destructor called" << '\n';
}


DiamondTrap::DiamondTrap(const std::string& name):
	ScavTrap(),
	FragTrap(),
	mName(name)
{
	ClapTrap::setName(std::string(name).append("_clap_name"));
	std::cout << "DiamondTrap " << mName << " constructor called" << '\n';
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap):
	ScavTrap(diamondTrap),
	FragTrap(diamondTrap)
{
	std::cout << "DiamondTrap copy constructor called" << '\n';
	mName = diamondTrap.getName();
	setName(diamondTrap.getName().append(std::string("_clap_name")));
	setHitPoints(diamondTrap.getHitPoints());
	setEnergyPoints(diamondTrap.getEnergyPoints());
	setAttackDamage(diamondTrap.getAttackDamage());
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap copy assignment operator called" << '\n';
	mName = diamondTrap.getName();
	setName(diamondTrap.getName().append(std::string("_clap_name")));
	setHitPoints(diamondTrap.getHitPoints());
	setEnergyPoints(diamondTrap.getEnergyPoints());
	setAttackDamage(diamondTrap.getAttackDamage());
	return *this;
}

std::string	DiamondTrap::getName(void) const
{
	return mName;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << mName << " and " << ClapTrap::getName() << '\n';
}
