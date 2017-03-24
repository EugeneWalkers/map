// map.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

//int main(int argc, char* argv[])
//{
//	if (argc > 3) {
//		string way = argv[1];
//		string doc = argv[2];
//		string endfile = argv[3];
//		cout << way << endl << doc << endl << argc << endl;
//		for (int i = 0; i < way.size(); i++) {
//			if (way[i] == '\\') {
//				way[i] = '/';
//			}
//		}
//		cout << way << endl << doc << endl << argc << endl;
//		if (way[way.size() - 1] != '/') {
//			way.append("/");
//		}
//		cout << way << endl << doc << endl << argc << endl;
//		if (way[3] != '/') {
//			way.insert(way.begin() + 3, '/');
//		}
//		cout << way << endl << doc << endl << argc << endl;
//		ifstream fin(way+doc);
//		int v = 1;
//		string t;
//		ofstream out(way+endfile);
//		while (fin >> t) {
//			out << t << ends << v << endl;
//		}
//		out.close();
//		fin.close();
//	}
//    return 0;
//}

int main() {

	std::string t;
	bool wasSpec = true;
	bool wasText = false;
	for (t; std::getline(std::cin, t);) {
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
		if (wasText) {
			std::cout << "\t" << 1 << std::endl;
		}
	}
	return 0;
}