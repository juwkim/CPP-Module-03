/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:02:56 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:52:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	:mName("juwon"),
	mHitPoints(10),
	mEnergyPoints(10),
	mAttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << '\n';
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << mName << " destructor called" << '\n';
}

ClapTrap::ClapTrap(const std::string& name)
	:mName(name),
	mHitPoints(10),
	mEnergyPoints(10),
	mAttackDamage(0)
{
	std::cout << "ClapTrap " << mName << " constructor called" << '\n';
}

ClapTrap::ClapTrap(const std::string& name, \
	const unsigned int hitPoints, \
	const unsigned int energyPoints, \
	const unsigned int attackDamage):
	mName(name),
	mHitPoints(hitPoints),
	mEnergyPoints(energyPoints),
	mAttackDamage(attackDamage)
{
	std::cout << "ClapTrap " << mName << " constructor called" << '\n';
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << '\n';
	mName = clapTrap.mName;
	mHitPoints = clapTrap.mHitPoints;
	mEnergyPoints = clapTrap.mEnergyPoints;
	mAttackDamage = clapTrap.mAttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" << '\n';
	mName = clapTrap.mName;
	mHitPoints = clapTrap.mHitPoints;
	mEnergyPoints = clapTrap.mEnergyPoints;
	mAttackDamage = clapTrap.mAttackDamage;
	return *this;
}

void ClapTrap::setName(std::string name)
{
	mName = name;
}

void ClapTrap::setHitPoints(const unsigned int hitPoints)
{
	mHitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(const unsigned int energyPoints)
{
	mEnergyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(const unsigned int attackDamage)
{
	mAttackDamage = attackDamage;
}

std::string	ClapTrap::getName(void) const
{
	return mName;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return mHitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return mEnergyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return mAttackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (mHitPoints == 0 || mEnergyPoints == 0) {
		std::cout << "ClapTrap " << mName << " cannot attack" << '\n';
		return;
	}
	std::cout << "ClapTrap " << mName << " attacks " << target
			<< ", causing " << mAttackDamage << " points of damage!" << '\n';
	--mEnergyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (mHitPoints == 0) {
		std::cout << "ClapTrap " << mName << " has already been defeated" << '\n';
		return;
	}
	if (mHitPoints < amount) mHitPoints = 0;
	else mHitPoints -= amount;
	std::cout << "ClapTrap " << mName << " is attacked and has "
		<< mHitPoints << " hit points remaning" << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (mHitPoints == 0 || mEnergyPoints == 0) {
		std::cout << "ClapTrap " << mName << " cannot be repaired" << '\n';
		return;
	}
	mHitPoints += amount;
	--mEnergyPoints;
	std::cout << "ClapTrap " << mName << " is repaired and has " 
		<< mHitPoints << " hit points remaning" << '\n';
}
