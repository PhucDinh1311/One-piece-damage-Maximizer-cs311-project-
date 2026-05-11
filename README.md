# One Piece Damage Maximizer

This project is a turn-based combat damage optimizer inspired by attacks from One Piece. The program reads attack data from a CSV file and determines the best combination of attacks to maximize total damage using limited mana, stamina, and turns.

## What It Does

- Reads attack information from actions.csv
- Uses C++ classes, structs, vectors, and file processing
- Uses recursion and backtracking to test different attack combinations
- Finds the highest possible damage output
- Displays the best attack combination on the screen

## Files

- main.cpp
- DamageMaximizer.cpp
- DamageMaximizer.h
- actions.csv
- Makefile
- report.pdf

## Compile

```bash
g++ -std=c++17 main.cpp DamageMaximizer.cpp -o damage
