#include <iostream>
#include "Window.h"

int main() {
	std::cout << "Create a Window..." << std::endl;

	Window* pWin = new Window();

	// Keep application up till user closes the window
	bool status = true;
	while (status) {
		if (!pWin->ProcessMessages()) {
			status = false;
			std::cout << "The Window is closed!" << std::endl;
		}

		// Prevent overusing of CPU
		Sleep(100);
	}

	return 0;
}