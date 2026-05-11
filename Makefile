damage: main.cpp DamageMaximizer.cpp
	g++ -std=c++17 main.cpp DamageMaximizer.cpp -o damage

clean:
	rm -f damage