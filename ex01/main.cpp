/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:03:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:54:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav("cucu");

	std::cout << "Name: " << scav.getName() << '\n';
	std::cout << "HitPoints: " << scav.getHitPoints() << '\n';
	std::cout << "EnergyPoints: " << scav.getEnergyPoints() << '\n';
	std::cout << "AttackDamage: " << scav.getAttackDamage() << '\n';
	scav.guardGate();
	scav.attack("kaka");
	scav.takeDamage(10);
	scav.beRepaired(5);
	return 0;
}
