#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <vector>
#include <regex>
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

struct Task{
	int position;
	string description;
};

string stringfyTask(Task task){
	string formatted_task = task.position + " - " + task.description;
	return formatted_task;
}

Task textToTask(string text){
	vector<string> parts;
	regex del(" - ");
	sregex_token_iterator it(text.begin(), text.end(), del, -1);
	sregex_token_iterator end;


	while(it != end){
		parts.push_back(*it);
	}

	Task task = { stoi(parts.at(0)) , parts.at(1) };

	return task;
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

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter anything to return." << std::endl;
	cin.get();
	system("clear");
}

void listTask(fstream* MyFile){
	string text_line;

	while( getline(*MyFile, text_line) ){
		cout << text_line << "\n";
	}

	MyFile->close();

	cout << "\nPress enter to return." << std::endl;
	cin.get();
	system("clear");
}

void addTask(fstream* MyFile){
	string new_task_text;

	system("clear");
	cout << "Write the new task:\n";
	getline(cin, new_task_text);

	MyFile->seekp(0, std::ios::end);
	*MyFile << new_task_text << "\n";

	cout << "\nThe new task was added. Press enter to return.";
	cin.get();
	system("clear");
}

int main(){
	string users_choice;
	int user_input_int = 0;

	system("clear");
	cout << "Task Manager\n";

	while(true){
		fstream MyFile("task-list.txt", fstream::in | fstream::out);
		printMainMenu();
		cin >> users_choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		user_input_int = stoi(users_choice);

		switch( convertIntToOption(user_input_int) ){
		case Option::LIST:
			system("clear");
			listTask(&MyFile);
			break;
		case Option::ADD:
			addTask(&MyFile);
			break;
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
			return 1;
		}

		MyFile.close();
	}

}
