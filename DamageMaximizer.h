#ifndef DAMAGE_MAXIMIZER_H
#define DAMAGE_MAXIMIZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Structure for attack actions
struct Action {

    string name;

    int damage;

    int manaCost;

    int staminaCost;
};

class DamageMaximizer {

private:

    vector<Action> actions;

    int bestDamage;

    vector<string> bestCombo;

public:

    DamageMaximizer();

    void loadActions(string filename);

    void findBestCombo(
        int mana,
        int stamina,
        int turns,
        int currentDamage,
        vector<string> currentCombo
    );

    void printBestCombo();
};

#endif