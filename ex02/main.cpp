/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:03:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:54:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag("cucu");

	std::cout << "Name: " << frag.getName() << '\n';
	std::cout << "HitPoints: " << frag.getHitPoints() << '\n';
	std::cout << "EnergyPoints: " << frag.getEnergyPoints() << '\n';
	std::cout << "AttackDamage: " << frag.getAttackDamage() << '\n';
	frag.highFivesGuys();
	frag.attack("kaka");
	frag.takeDamage(10);
	frag.beRepaired(5);
	return 0;
}
