#ifndef ARCADE_TROLL_H
#define ARCADE_TROLL_H

#include "monster.h"

class Troll : public Monster {
public:
    Troll();
    int attack_damage() const override;
};

#endif 
