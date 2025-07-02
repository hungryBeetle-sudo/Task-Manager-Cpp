#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

enum class Option{
	LIST,
	UPDATE,
	ADD,
	DELETE,
	EXIT,
	INVALID
};

Option convertIntToOption(int number){
	if(number == 1) return Option::LIST;
	else if(number == 2) return Option::UPDATE;
	else if(number == 3) return Option::ADD;
	else if(number == 4) return Option::DELETE;
	else if(number == 5) return Option::EXIT;
	else return Option::INVALID;
}

void printMainMenu(){
	string main_menu = R"(
1 - List tasks
2 - Update task
3 - Add task
4 - Delete task
5 - Exit)";

	cout << main_menu << "\n\n";
}

int main(){
	fstream MyFile("task-list.txt", fstream::in | fstream::out);
	string text_fragment;
	string file_full_text;
	string users_choice;

	while( getline(MyFile, text_fragment) )
		file_full_text.append(text_fragment + "\n");

	system("clear");
	cout << "Task Manager\n";
	printMainMenu();


	while(true){
		cin >> users_choice;

		switch( stoi(users_choice) ){
		case 5:
			MyFile.close();
			return 0;
			break;
		default:
			system("clear");
			printMainMenu();
			cout << "Invalid option: " << users_choice << "\n\n";
		}
	}

}
