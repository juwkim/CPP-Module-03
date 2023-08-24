/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:03:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 07:20:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("cucu");

	std::cout << "Name: " << diamond.getName() << '\n';
	std::cout << "HitPoints: " << diamond.getHitPoints() << '\n';
	std::cout << "EnergyPoints: " << diamond.getEnergyPoints() << '\n';
	std::cout << "AttackDamage: " << diamond.getAttackDamage() << '\n';
	diamond.whoAmI();
	diamond.attack("kaka");
	diamond.takeDamage(10);
	diamond.beRepaired(5);
	return 0;
}
