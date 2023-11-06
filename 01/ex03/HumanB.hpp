#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB {
private:
	std::string name;
	Weapon*     weaponPTR; // ptr

public:
	            HumanB(std::string name_);
	void        setWeapon(Weapon& weaponPTR_); // &
	void        attack(void);
};

#endif
