#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "cpu.hpp"
#include "mmu.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Emulator {
    public:
    Emulator(char *romPath);
    void run();

    private:
    CPU cpu;
    MMU mmu;

    sf::Window win;
    sf::Event ev;
    sf::Clock timer;

    int divCounter = 0;
    int tmaCounter = 0;

    void updateTimers(int cycles);
    void handleInterrupts();
    void handleEvents();
};

#endif // "emulator.hpp" included
