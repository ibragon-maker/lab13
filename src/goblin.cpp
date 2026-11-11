#include "goblin.h"

Goblin::Goblin() : Monster("Goblin", 30) {}

int Goblin::attack_damage() const {
    return 5;
}
