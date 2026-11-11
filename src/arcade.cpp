#include "arcade.h"
#include <iostream>

/// @file arcade.cpp
/// @brief Implementation of the Arcade class.

Arcade::Arcade() : m_count(0) {
    for (int i = 0; i < max_games; ++i) {
        m_games[i] = nullptr;
    }
}

Arcade::~Arcade() {
    for (int i = 0; i < m_count; ++i) {
        delete m_games[i];
        m_games[i] = nullptr;
    }
}

void Arcade::add(Game *game) {
    if (m_count < max_games && game != nullptr) {
        m_games[m_count++] = game;
    } else {
        delete game; // Take ownership and delete if full or invalid
    }
}

void Arcade::run() {
    std::string line;
    while (true) {
        std::cout << "\n--- ARCADE ---\n";
        for (int i = 0; i < m_count; ++i) {
            std::cout << i + 1 << ". " << m_games[i]->title() << "\n";
        }
        std::cout << "0. Quit\n";
        std::cout << "Choose: ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        int choice = 0;
        try {
            choice = std::stoi(line);
        } catch (...) {
            std::cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= m_count) {
            int index = choice - 1;
            m_games[index]->play();
            std::cout << m_games[index]->title() << " score: " << m_games[index]->last_score() << "\n";
        } else {
            std::cout << "Please enter 1-" << m_count << ", or 0 to quit.\n";
        }
    }
    std::cout << "Goodbye.\n";
}
