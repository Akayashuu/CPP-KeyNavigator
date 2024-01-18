
// cpp_console_picker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "console_picker.h";
#include "thread"

int main()
{
	std::vector<K_V> kvs = std::vector<K_V>();
	kvs.push_back(K_V{ "Choix 1", "1" });
	kvs.push_back(K_V{ "Choix 2", "2" });
	kvs.push_back(K_V{ "Choix 3", "3" });
	kvs.push_back(K_V{ "Choix 4", "4" });
	ConsolePicker picker = ConsolePicker(kvs);
	std::thread threadRun(&ConsolePicker::run, &picker);
	std::thread threadDebugger(&ConsolePicker::debugger, &picker);

	threadRun.join();
	threadDebugger.join();

}