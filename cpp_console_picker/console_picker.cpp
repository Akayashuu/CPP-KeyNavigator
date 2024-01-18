#include "console_picker.h"
#include <Windows.h>
#include <iostream>
#include <thread>



ConsolePicker::ConsolePicker(std::vector<K_V>& choices, ConsolePickerOptions options): choices(choices), options(options) {}
ConsolePicker::~ConsolePicker() {};

void ConsolePicker::set_choices(std::vector<K_V>& choices) {
    this->choices = choices;
};

void ConsolePicker::set_quit_is_enabled(bool quit_is_enabled) {
    this->options.quit_is_enabled = quit_is_enabled;
};



void ConsolePicker::run() {
    while (true) {
        if ((GetAsyncKeyState('Q') & 0x8001) && this->options.quit_is_enabled) { break; };
        if (GetAsyncKeyState(VK_UP) & 0x8001) {
            std::cout << "Up" << std::endl;
            if (this->current_index >= 0) {
				this->current_index--;
			}
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
            std::cout << "Down" << std::endl;
            if (this->current_index < this->choices.size() - 1) {
                this->current_index++;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

};

void ConsolePicker::debugger() {
    std::cout << "Debugging..." << std::endl;
    std::cout << "Choices: " << std::endl;
    for (int i = 0; i < this->choices.size(); i++) {
        std::cout << "Choice " << i << ": " << this->choices[i].name << " Key: " << this->choices[i].value << std::endl;
    }
    while (true) {
        std::cout << "Current index: " << this->current_index << std::endl; 
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
};