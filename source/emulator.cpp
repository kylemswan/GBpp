#include "emulator.hpp"

Emulator::Emulator(char *romPath) {
    mmu.loadROM(romPath);

    cpu.reset();
    cpu.bindMMU(&mmu);

    win.create(sf::VideoMode(640, 320), "gbpp");
}

void Emulator::run() {
    while (win.isOpen()) {
        // main game logic is updated at 60FPS
        if (timer.getElapsedTime().asSeconds() >= 1.0 / 60) {
            
            // CPU executes 4194304 cycles per second == 69905 per frame
            while (cpu.getCycles() < 69905) {
                cpu.run();
            }
            cpu.resetCycles();

            // update timers, draw graphics, handle interrupts, etc... here

            timer.restart();
        }

        handleEvents();
    }
}

void Emulator::handleEvents() {
    while (win.pollEvent(ev)) {
        // check for window 'X' clicks
        if (ev.type == sf::Event::Closed) {
            win.close();
        }
        // check for 'ESC' key presses
        if (ev.key.code == sf::Keyboard::Escape) {
            win.close();
        }
    }
}
