#include <iostream>
using namespace std;
#include <string>
#include <list>

// To-Do List Manager: Build a console-based to-do list application. Allow users to add, remove, and view tasks.

class Task {
    public:
        int id;
        string description;
};

void addTask(list<Task> tasks, Task newTask){
    cout << "We are inside the addTask function" << endl;
    tasks.push_front(newTask);
    for (Task i: tasks){
        cout << i.description << " sono \n";
    }
}

void removeTask(list<Task> tasks, Task newTask){
    cout << "We are inside the removeTask function" << endl;
}

void viewTask(list<Task> tasks, Task newTask){
    cout << "We are inside the viewTask function" << endl;
}


int main(){
    list<Task> tasks;
    cout << "To do List Manager" << endl;
    cout << "Please choose an action:" << endl;
    cout << "1: Add task" << endl;
    cout << "2: Remove task" << endl;
    cout << "3: View task" << endl;

    string option;
    while (true){
        cin >> option;
        Task newTask;

        if (option == "1"){
            newTask.id = 2;
            newTask.description = "anamana";
            addTask(tasks, newTask);
            break;
        }

        if (option == "2"){
            removeTask(tasks, newTask);
            break;
        }

        if (option == "3"){
            viewTask(tasks, newTask);
            break;
        }

        cout << "You must choose betwee 1 and 3" << endl;

    }


    
    return 0;
}