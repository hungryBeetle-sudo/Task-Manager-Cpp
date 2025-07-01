#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::fstream MyFile("task-list.txt", std::fstream::in | std::fstream::out);

	std::string text_fragment;
	std::string file_full_text;

	while( std::getline(MyFile, text_fragment) )
		file_full_text.append(text_fragment + "\n");

	std::cout << file_full_text;

        MyFile.close();

	return 0;
}
