#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#include<unordered_set>
#include<time.h>

using namespace std;

class task
{
private:
	string name, description,category;
	int priority, id;
public:
	bool set_name(string Name) {
		if (Name.size() > 20) {
			printf("--Invalid name\n --Please make it less than 20 symbols");
			return false;
		}
		else {
			name = Name;
			return true;
		}
	}
	bool set_priority(int Pri) {
		if (Pri < 0 || Pri>99) {
			printf("--Invalid priority\n --Please make it from 0 to 99");
			return false;
		}
		else {
			priority = Pri;
			return true;
		}
	}
	void set_description(string Des) {
		description = Des;
	}
	void set_category(string Cat) {
		category = Cat;
	}
	void set_time() {

	}
	void set_id(int Id) {
		id = Id;
	}
	void print() {
		printf("%4d  %20s  %2d  %20s \n", id, name, priority,category);
	}
	void show_description() {
		printf("\n%s\n", description);
	}
};


class list_of_tasks
{
private:
	vector<task> li;
	unordered_set<string> categories ={"chores","homework","none","work"};

public:
	void add_task() {

	}
	void remove_task(int id) {

	}
	void filter_tasks(int by) {

	}
	void sort_tasks(int by) {

	}
	void remove_all() {
		li.clear();
	}
	void change_task(int id) {

	}
	void add_category() {

	}
	void remove_category() {

	}
	void show_categories() {

	}
	void show() {
		printf("%4s  %20s  %2s  %20s", "id", "name       ", "pr", "      category     ");
		for (task t : li) {
			t.print();
		}
	}
	int get_number_of_tasks() {
		return li.size();
	}

};
void show_commands() {
	printf(" -add- to add a task \n");
	printf(" -remove- to remove a task with id\n");
	//printf(" -show- to show all curent tasks \n");
	printf(" -change- to change in task with id \n");
	printf(" -filter- to show tasks only with \n");
	printf(" -addcat- to add a category\n");
	printf(" -remcat- to remove a category");
	printf(" -remall- to remove all current tasks \n");
}
void ask_id(int &id) {
	printf("please enter id of the task");
	cin >> id; 
}
bool check_id(int &id,int &sz) {
	if (id > sz) {
		printf("--Invalid id \n --Please make it from 1 to %d \n --Or -back- to cancel", sz);
	}
}
int main() {
	list_of_tasks li;
	while (1) {
		li.show();
		printf("Please enter a command\n");
		printf(" -cm- to show commands\n");
		string input;
		int id, by, sz = li.get_number_of_tasks();
		cin >> input;
		if (input == "add") {
			li.add_task();
		}
		else if (input == "remove") {
			ask_id(id);
			li.remove_task(id);
		}
		else if (input=="change") {
			ask_id(id);
			if (id > sz) {
				
			}
			li.change_task(id);
		}else 
	}
	


}