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
		printf("%4d  %20s  %2d", id, name, priority);

	}
	void show_description() {
		printf("\n%s\n", description);
	}
};


class list_of_tasks
{
private:
	vector<task> li;
	unordered_set<string> categories;

public:
	void add_task() {

	}
	void remove_task() {

	}
	void filter_tasks() {

	}
	void sort_tasks() {

	}
	void remove_all() {
		li.clear();
	}
	void change_task() {

	}
	void add_category() {

	}
	void remove_category() {

	}
	void show() {
		printf("%4s  %20s  %2s  %20s", "id", "name       ", "pr", "      category     ");
		for (task t : li) {
			
		}
	}
	int get_number_of_tasks() {
		return li.size();
	}

};

int main() {
	list_of_tasks li;
	printf("Please enter a command\n");
	printf(" -add- to add a task \n");
	printf(" -remove- -id- to remove a task with id\n");
	printf(" -show- to show all curent tasks \n");
	printf(" -change- -id- to change in task with id \n");
	printf(" -filter- -id- to change in task with id \n");
	printf(" -filter- -id- to change in task with id \n");
	printf(" -remall- to remove all current tasks \n");

}