/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 06:32:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/25 07:11:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		virtual ~FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& fragTrap);
		FragTrap& operator=(const FragTrap& frapTrap);

		virtual void highFivesGuys(void);
};
