#include "DamageMaximizer.h"

// Constructor
DamageMaximizer::DamageMaximizer() {
    bestDamage = 0;
}

// Load actions from CSV file
void DamageMaximizer::loadActions(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;

    // Skip header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);

        string name;
        string damageStr;
        string manaStr;
        string staminaStr;

        getline(ss, name, ',');
        getline(ss, damageStr, ',');
        getline(ss, manaStr, ',');
        getline(ss, staminaStr, ',');

        Action action;
        action.name = name;
        action.damage = stoi(damageStr);
        action.manaCost = stoi(manaStr);
        action.staminaCost = stoi(staminaStr);

        actions.push_back(action);
    }

    file.close();
}

// Recursively try all possible action combinations
void DamageMaximizer::findBestCombo(
    int mana,
    int stamina,
    int turns,
    int currentDamage,
    vector<string> currentCombo
) {
    // Base case: no turns left
    if (turns == 0) {
        if (currentDamage > bestDamage) {
            bestDamage = currentDamage;
            bestCombo = currentCombo;
        }

        return;
    }

    // Try every action
    for (Action action : actions) {
        if (mana >= action.manaCost && stamina >= action.staminaCost) {
            currentCombo.push_back(action.name);

            findBestCombo(
                mana - action.manaCost,
                stamina - action.staminaCost,
                turns - 1,
                currentDamage + action.damage,
                currentCombo
            );

            currentCombo.pop_back();
        }
    }
}

// Print best result
void DamageMaximizer::printBestCombo() {
    cout << "Best Damage: " << bestDamage << endl;
    cout << "Best Combo: ";

    for (int i = 0; i < bestCombo.size(); i++) {
        cout << bestCombo[i];

        if (i != bestCombo.size() - 1) {
            cout << " -> ";
        }
    }

    cout << endl;
}