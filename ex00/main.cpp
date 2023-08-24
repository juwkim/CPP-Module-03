/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:03:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 06:54:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("cucu");

	std::cout << "Name: " << clap.getName() << '\n';
	std::cout << "HitPoints: " << clap.getHitPoints() << '\n';
	std::cout << "EnergyPoints: " << clap.getEnergyPoints() << '\n';
	std::cout << "AttackDamage: " << clap.getAttackDamage() << '\n';
	clap.attack("kaka");
	clap.takeDamage(3);
	clap.beRepaired(5);
	return 0;
}
