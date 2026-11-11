#include "monster.h"

Monster::Monster(std::string name, int health)
    : m_name(name), m_health(health) {}

std::string Monster::describe() const {
    return m_name + " with " + std::to_string(m_health) + " health.";
}

void Monster::take_damage(int amount) {
    m_health -= amount;
    if (m_health < 0) {
        m_health = 0;
    }
}

bool Monster::is_dead() const {
    return m_health <= 0;
}

const std::string &Monster::name() const {
    return m_name;
}
