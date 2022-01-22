#include <iostream>
#include <array>
#include <random>

class ConwayGameOfLife {

private:
    static const int N = 20;
    std::array<std::array<bool, N>, N> grid;
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

    void init_grid() {
        float c = dist(rng);
    }

};
std::random_device ConwayGameOfLife::dev{};
std::mt19937 ConwayGameOfLife::rng{dev()};
std::uniform_real_distribution<> ConwayGameOfLife::dist{0.0, 1.0};

int main() {
    std::cout << "Hello, World!" << std::endl;
    //TODO print_grid();
    return 0;
}
