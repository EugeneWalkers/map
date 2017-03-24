// map.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>


int main() {

	std::string t;
	bool wasSpec = true;
	bool wasText = false;
	for (t; std::getline(std::cin, t);) {
		wasSpec = true;
		for (int i = 0; i < t.length(); i++) {
			
			if (t[i] >= 97 && t[i] <= 122) {
				std::cout << t[i];
				wasSpec = false;
				wasText = true;
			}
			else if (t[i] >= 224 && t[i] <= 255) {
				std::cout << t[i];
				wasSpec = false;
				wasText = true;
			}
			else if (t[i] >= 65 && t[i] <= 91) {
				t[i] += 32;
				std::cout << t[i];
				wasSpec = false;
				wasText = true;
			}
			else if (t[i] >= 192 && t[i] <= 223) {
				t[i] += 32;
				std::cout << t[i];
				wasSpec = false;
				wasText = true;
			}
			else if (!wasSpec) {
				std::cout << "\t" << 1 << std::endl;
				wasSpec = true;
			}
		}
		if (wasText && !wasSpec) {
			std::cout << "\t" << 1 << std::endl;
		}
	}
	return 0;
}