/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:02:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 07:36:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(void);
		virtual	~ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const std::string& name, \
			const unsigned int hitPoints, \
			const unsigned int energyPoints, \
			const unsigned int attackDamage);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& clapTrap);

		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);

		void setName(std::string name);
		void setHitPoints(const unsigned int hitPoints);
		void setEnergyPoints(const unsigned int energyPoints);
		void setAttackDamage(const unsigned int attackDamage);

		virtual std::string		getName(void) const;
		unsigned int			getHitPoints(void) const;
		unsigned int			getEnergyPoints(void) const;
		unsigned int			getAttackDamage(void) const;

	private:
		std::string		mName;
		unsigned int	mHitPoints;
		unsigned int	mEnergyPoints;
		unsigned int	mAttackDamage;
};
