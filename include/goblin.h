#ifndef ARCADE_GOBLIN_H
#define ARCADE_GOBLIN_H

#include "monster.h"

class Goblin : public Monster {
public:
    Goblin();
    int attack_damage() const override;
};

#endif 
