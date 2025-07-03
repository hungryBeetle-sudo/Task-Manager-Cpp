#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
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

void listTasks(string file_full_text){
	stringstream ss(file_full_text);
	char delimiter = '\n';
	string aux_string;

	while( getline(ss, aux_string, delimiter) ){
		cout << aux_string << "\n";
	}

	cout << "\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter anything to return." << std::endl;
	cin.get();
	system("clear");
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


	while(true){
		printMainMenu();

		cin >> users_choice;
		int user_input_int = stoi(users_choice);

		switch( convertIntToOption(user_input_int) ){
		case Option::LIST:
			system("clear");
			listTasks(file_full_text);
			break;
		case Option::ADD:
		case Option::UPDATE:
		case Option::DELETE:
			system("clear");
			cout << "This option isn't properly working.\n\n";
			break;
		case Option::EXIT:
			MyFile.close();
			return 0;
		case Option::INVALID:
			system("clear");
			cout << "Invalid option: " << users_choice << "\n\n";
			break;
		default:
			system("clear");
			cout << "Unknown error. User input: " << users_choice << "\n\n";
		}
	}

}
