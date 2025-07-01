#include <iostream>
#include <fstream>
#include <string>

enum class Option{
	LIST,
	UPDATE,
	ADD,
	DELETE,
	EXIT
};

int main(){
	std::fstream MyFile("task-list.txt", std::fstream::in | std::fstream::out);

	std::string text_fragment;
	std::string file_full_text;

	while( std::getline(MyFile, text_fragment) )
		file_full_text.append(text_fragment + "\n");

	//std::cout << file_full_text;

	std::string users_choice;

	std::cout << "Task Manager\n";
	std::cout << R"(
	1 - List tasks
	2 - Update task
	3 - Add task
	4 - Delete task
	5 - Exit)" << std::endl;

        
	while(true){
		std::cin >> users_choice;

		switch( stoi(users_choice) ){
		case 5:
			MyFile.close();
			return 0;
			break;
		default:
			std::cout << "Invalid option: " << users_choice << std::endl;
		}
	}

}
