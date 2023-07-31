#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <stdlib.h>

#define all(x) (x).begin(),(x).end()

using namespace std;

vector<string> categories = { "chores","homework","none","work" };

void add_category(string &Cat) {
	while (check_category(Cat)) {
		printf("--Category is already used \n --Please enter new category \n");
		cin >> Cat;
	}
	categories.push_back(Cat);

}
void remove_category(string& Cat) {
	while (!check_category(Cat)) {
		printf("--Category doesn't exist\n --Please enter existing category \n");
		cin >> Cat;
	}
	categories.erase(find(all(categories), Cat));
}
void show_categories() {
	for (string Cat : categories) {
		printf("- %20s \n", Cat);
	}
}
//void ask_cat(string& cat) {
//	printf("--Please enter category \n");
//	cin >> cat;
//}
bool check_category(string& Cat) {
	if (find(all(categories), Cat) == categories.end()) {
		return false;
	}
	else return true;
}
class task
{
private:
	string name, description,category;
	int priority, id;
	bool show;
public:
	void set_name(string &Name) {
		while (!check_name(Name)) {
			cin >> Name;
		}
		name = Name;
	}
	bool check_name(string& Name) {
		if (Name.size() > 20) {
			printf("--Invalid name\n --Please make it less than 20 symbols \n");
			return false;
		}
		else return true;
	}
	void set_priority(int &Pri) {
		while (!check_priority(Pri)) {
			cin >> Pri;
		}
		priority = Pri;
	}
	bool check_priority(int& Pri) {
		if (Pri < 0 || Pri>99) {
			printf("--Invalid priority\n --Please make it from 0 to 99 \n");
			return false;
		}
		else return true;
	}
	void set_description(string &Des) {
		description = Des;
	}
	void set_category(string &Cat) {
		while (!check_category(Cat)) {
			cin >> Cat;
		}
		category = Cat;
	}

	void set_time() {

	}
	void print() {
		printf("%4d  %20s  %2d  %20s \n", id, name, priority,category);
	}
	void show_description() {
		printf("\n%s\n", description);
	}
	task() {
		string Name, Des, Cat;
		int Pri, int Id;
		bool Show;
		printf("-Please enter the name, it must be less then 20 symbols \n");
		cin >> Name;
		this->set_name(Name);
		printf("-Please enter the priotity, it must from 0 to 99 \n");
		cin >> Pri;
		this->set_priority(Pri);
		printf("-Please enter the description \n");
		cin >> Des;
		this->set_description(Des);
		printf("-Please enter the category \n");
		
		category = Cat;
		priority = Pri;
		id = Id;
		show = Show;
	}
};



class list_of_tasks
{
private:
	vector<task> li;
public:
	void add_task() {

	}
	void remove_task(int &id) {

	}
	void ask_id(int& id) {
		printf("--Please enter id of the task \n");
		cin >> id;
	}
	task get_task(int &id) {
		return li[id - 1];
	}
	void filter_tasks(int &by) {

	}
	void sort_tasks(int &by) {

	}
	void remove_all() {
		li.clear();
	}
	void change_task(int &id) {

	}

	int get_number_of_tasks() {
		return li.size();
	}
	bool check_id(int &id) {
		if (id > li.size()) {
			printf("--Invalid id \n --Please make it from 1 to %d \n",li.size());
			return false;
		}
		return true;
	}

	void show() {
		printf("%4s  %20s  %2s  %20s \n", "id", "name       ", "pr", "      category     ");
		for (task t : li) {
			t.print();
		}
	}


};
void show_commands() {
	printf(" -add- to add a task \n");
	printf(" -remove- to remove a task with id\n");
	//printf(" -show- to show all curent tasks \n");
	printf(" -change- to change in task with id \n");
	printf(" -filter- to show tasks only with \n");
	printf(" -addcat- to add a category \n");
	printf(" -remcat- to remove a category \n");
	printf(" -remall- to remove all current tasks \n");
	printf(" -des- to show description of certain task");
}



int main() {
	//system("cls"); to clear output
	//chrono for time
	list_of_tasks li;
	while (1) {
		li.show();
		printf("Please enter a command\n");
		printf(" -cm- to show commands\n");
		string input, cat;
		int id, by, sz = li.get_number_of_tasks();
		cin >> input;
		if (input == "cm") {
			show_commands();
		}
		else if (input == "add") {
			li.add_task();
		}
		else if (input == "remove") {
			do {
				li.ask_id(id);
			} while (!li.check_id(id));
			li.remove_task(id);
		}
		else if (input == "change") {
			do {
				li.ask_id(id);
			} while (!li.check_id(id));
			li.change_task(id);
		}
		else if (input == "des") {
			do {
				li.ask_id(id);
			} while (!li.check_id(id));
			li.get_task(id).show_description();
		}
		else if (input == "addcat") {
			cin >> cat;
			add_category(cat);
		}
		else if (input == "remcat") {
			cin >> cat;
			remove_category(cat);
		}
		else if (input == "remall") {
			li.remove_all();
		}
		else {
			printf("--Invalid command, please try again \n");
		}
		printf(" --Type anything to continue\n");
		cin >> input;
		system("cls");
	}
	


}