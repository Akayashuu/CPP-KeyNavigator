#ifndef CONSOLE_PICKER_H
#define CONSOLE_PICKER_H
#include <iostream>
#include <vector>


struct K_V {
	std::string name;
	std::string value;
};

/*
	Options Type of the picker.
		1. quit_is_enabled is a boolean that allows the user to quit the picker by pressing the Q key.
*/
struct ConsolePickerOptions {
	/*
		quit_is_enabled is a boolean that allows the user to quit the picker by pressing the Q key.
	*/
	bool quit_is_enabled;
};

class ConsolePicker
{
	public:
		/*
			Choices is a vector of K_V structs.
			Each K_V struct contains a name and a value.
		*/
		std::vector<K_V> choices;
		/*
			Current index of the selected choice.
		*/
		int current_index = 0;
		/*
			Options of the picker.
			@see ConsolePickerOptions
		*/
		ConsolePickerOptions options;

		/*
			Constructor
		*/
		ConsolePicker(std::vector<K_V>& choices, ConsolePickerOptions options = { true });
		/*
			Destructor
		*/
		~ConsolePicker();
		/*
			Example:
				std::vector<K_V> kvs = std::vector<K_V>();
					kvs.push_back(K_V{ "Choix 1", "1" });
					kvs.push_back(K_V{ "Choix 2", "2" });
					kvs.push_back(K_V{ "Choix 3", "3" });
					kvs.push_back(K_V{ "Choix 4", "4" });
				ConsolePicker picker = ConsolePicker(kvs);
				picker.run();
		*/
		void run();
		/*
			Set new choices for the picker.
		*/
		void set_choices(std::vector<K_V>& choices);
		/*
			Debugger
		*/
		void debugger();

		/*
			set quit_is_enabled option of the picker.
		*/
		void set_quit_is_enabled(bool quit_is_enabled);


};

#endif
// Path: cpp_console_picker/console_picker.cpp