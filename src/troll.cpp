#include "troll.h"

Troll::Troll() : Monster("Troll", 50) {}

int Troll::attack_damage() const {
    return 10;
}
