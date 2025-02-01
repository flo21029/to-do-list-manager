using namespace std;
#include <iostream>
#include <string>
#include <list>

// To-Do List Manager: Build a console-based to-do list application. Allow users to add, remove, and view tasks.

class Task {
    public:
        int id;
        string description;
};

int getGreatestId(list<Task> tasks){
    int greater = 0;

    for (Task i: tasks){
        if (greater < i.id){
            greater = i.id;
        }
    }
    return greater;

}

int getTaskId(list<Task> tasks){
    if (tasks.empty()){
        return 1;
    }
    cout << "Task ID Found inside getTaskId Function: " << getGreatestId(tasks);
    return getGreatestId(tasks) + 1;
}

int main(){
    list<Task> tasks;
    string option;
    list<int> indexes;
    while (true){
        cout << "\nTo do List Manager\n";
        cout << "Please choose an action:\n";
        cout << "1: Add task\n";
        cout << "2: Remove task\n";
        cout << "3: View task\n";

        cin >> option;
        Task newTask;

        if (option == "1"){
            cout << "Enter the new Task description: (Add a forward slash / at the end of the description and then press Enter to finish describing it.\n";
            std::getline(cin, newTask.description, '/');
            
            newTask.id = getTaskId(tasks);
            tasks.push_front(newTask);
            indexes.push_front(newTask.id);
            cout << "\nID Generated for this Task: " << newTask.id << "\n";
            continue;
        }

        if (option == "2"){
            cout << "Enter the ID of the Task to be deleted: \n";
            int id;
            cin >> id;

            for (Task i: tasks){
                if (i.id == id){
                    indexes.remove((int)i.id);
                    cout << "Task deleted: Description: " << i.description << ". ID: " << i.id << "\n";
                }
                
            }

            for (int i: indexes){
                cout << "Index existent: " << i << "\n";
            }
            
            continue;
        }

        if (option == "3"){
            cout << "Enter the ID of the Task to be Viewed: \n";
            int id;
            cin >> id;
            for (int index: indexes){
                if (id == index){
                    for (Task task: tasks){
                        if (task.id == id){
                            cout << "Task View: Description: " << task.description << ". ID: " << task.id << "\n";
                        }
                    }
                }
            }
            continue;

        }

        cout << "You must choose betwee 1 and 3" << endl;

    }


    
    return 0;
}