#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class ClapTrap {
public: 
  std::string  _name;
  unsigned int _hitPoints;    // the health
  unsigned int _energyPoints; // can’t do anything if it has no hit points or energy points
  unsigned int _attackDamage;

               ClapTrap   ();
               ClapTrap   (std::string name);
               ClapTrap   (const ClapTrap &obj);
               ~ClapTrap  ();
  ClapTrap&    operator = (const ClapTrap &obj);

  void         attack     (const std::string& target); // causes its target to lose <attack damage> hit points, costs 1 energyPoint
  void         takeDamage (unsigned int amount);
  void         beRepaired (unsigned int amount);       // gets <amount> hit points back, costs 1 energyPoint
};

#endif
