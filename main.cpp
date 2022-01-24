#include <iostream>
#include <array>
#include <random>

class ConwayGameOfLife {

private:
    static const int N = 50;
    // All boundary cells are currently treated as always dead, ie. 0.
    std::array<std::array<bool, N>, N> grid = {};
    // This neighbours array should be static,somehow, I think
    const std::array<std::array<int, 2>, 8> neighbours = 
    {{
	{ 1, 0 },
	{ 1, 1 },
	{ 0, 1 },
	{ -1, 1 },
	{ -1, 0 },
	{ -1, -1 },
	{ 0, -1 },
	{ 1, -1 }
    }};
	

    static std::random_device dev;
    // TODO: need to be replace if we want to save specific seeds
    static std::mt19937 rng;
    static std::uniform_real_distribution<> dist;

// init_grid ~ initialise grid, fill with random stuff
// print_grid
// next_step
// pad_input (?)
// read_input (from file); could be random, padded, or tiled

private:
    static char cell_representation(bool b) {
        return b ? '#' : '.';
    }

    static bool step_rules(bool center_alive, int sum_neighbours){
	if (center_alive)
	    return 3 <= sum_neighbours && sum_neighbours <= 4;
	return sum_neighbours == 3;
    }

public:
    ConwayGameOfLife()
    {
    }
    void print_grid() {
        for (auto y : grid) {
            for (auto x : y) {
                std::cout << cell_representation(x);
            }
            std::cout << std::endl;
        }
    }

    void init_grid(float density) {
	for (int i = 1; i < N-1; ++i){
	    for (int j = 1; j < N-1; ++j){
		float c = dist(rng);
		grid[i][j] = c <= density;
	    }
	}
    }

    void next_step()
    {
	std::array<std::array<bool, N>, N> next = {};
	for (int i = 1; i < N-1; ++i){
	    for (int j = 1; j < N-1; ++j){
		int alive = 0;
		for (auto p : neighbours){
		    alive += grid[i+p[0]][j+p[1]];
		} 
		next[i][j] = step_rules(grid[i][j], alive);
	    }
	}
	grid = next;

    }

};
std::random_device ConwayGameOfLife::dev{};
std::mt19937 ConwayGameOfLife::rng{dev()};
std::uniform_real_distribution<> ConwayGameOfLife::dist{0.0, 1.0};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ConwayGameOfLife gol;
    gol.init_grid(0.3);
    for(int n = 0; n < 50; ++n)
    {
	std::cout << "Steps: " << n << "\n";
	gol.print_grid();
	gol.next_step();
    }
    return 0;
}
