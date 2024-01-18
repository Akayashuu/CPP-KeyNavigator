#include "keyNavigator.h"
#include <Windows.h>
#include <iostream>
#include <thread>

KeyNavigator::KeyNavigator(std::vector<K_V>& choices, KeyNavigatorOptions options): choices(choices), options(options) {}
KeyNavigator::~KeyNavigator() {};

void KeyNavigator::set_choices(std::vector<K_V>& choices) {
    this->choices = choices;
};

void KeyNavigator::set_quit_is_enabled(bool quit_is_enabled) {
    this->options.quit_is_enabled = quit_is_enabled;
};

void KeyNavigator::run() {
    while (true) {
        if ((GetAsyncKeyState('Q') & 0x8001) && this->options.quit_is_enabled) {std::abort();break;};
        if (GetAsyncKeyState(VK_UP) & 0x8001) {
            std::cout << "Up" << std::endl;
            if (this->current_index == this->choices.size()-1) {}
            else {
				this->current_index++;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
            std::cout << "Down" << std::endl;
            if(this->current_index > this->choices.size() || this->current_index-1 < 0) {}
            else {
                this->current_index--;
            }
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8001) {
			std::cout << "Enter" << std::endl;
			std::cout << "Current index: " << this->current_index << std::endl;
			std::cout << "Value: " << this->choices[this->current_index].value << std::endl;
            break;
		}
        Sleep(100);
    }

};

void KeyNavigator::debugger() {
    std::cout << "Debugging..." << std::endl;
    std::cout << "Choices: " << std::endl;
    for (int i = 0; i < this->choices.size(); i++) {
        std::cout << "Choice " << i << ": " << this->choices[i].name << " Key: " << this->choices[i].value << std::endl;
    }
    while (true) {
        std::cout << "Current index: " << this->current_index << std::endl; 
        Sleep(100);
    }
};