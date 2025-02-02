using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <fstream>

class Task {
    // Creation of a Task type that will hold the values that the user will enter for every task to be stored
    public:
        int id;
        string description;
        
};

int getGreatestId(list<Task> tasks){
    // Find or create a new ID for a new task created, based on the last ID number previously assigned
    int greater = 0;
    for (Task i: tasks){
        if (greater < i.id){
            greater = i.id;
        }
    }
    return greater;
}

int getTaskId(list<Task> tasks){
    // This works together with the getGreatedsId function to create a new ID for a new task, if the list is empty, then it returns the value 1 as the first ID value assigned to a task.
    if (tasks.empty()){
        return 1;
    }
    cout << "Task ID Found inside getTaskId Function: " << getGreatestId(tasks);
    return getGreatestId(tasks) + 1;
}

int main(){
    // To-Do List Manager: Build a console-based to-do list application. Allow users to add, remove, and view tasks.
    list<Task> tasks;
    string option;
    list<int> indexes;
    while (true){
        // We print the menu with the options the user has to choose from.
        cout << "\nTo do List Manager\n";
        cout << "Please choose an action:\n";
        cout << "1: Add task\n";
        cout << "2: Remove task\n";
        cout << "3: View task\n";

        // We ask the user to select an option through terminal
        cin >> option;
        Task newTask;

        if (option == "1"){
            // We add a new object
            cout << "Enter the new Task description: (Add a forward slash / at the end of the description and then press Enter to finish describing it.\n";
            std::getline(cin, newTask.description, '/');
            
            // First we obtain a new ID for this task
            newTask.id = getTaskId(tasks);

            // Then we add this new task to the complete list of tasks
            tasks.push_front(newTask);

            // We keep an index so we can more easily manipulate the elements that are going to be displayed throughout the program execution
            indexes.push_front(newTask.id);
            cout << "\nID Generated for this Task: " << newTask.id << "\n";
            continue;
        }

        if (option == "2"){
            // We will delete a task
            cout << "Enter the ID of the Task to be deleted: \n";
            int id;

            // We request the user to enter the ID to be deleted through terminal
            cin >> id;

            for (Task i: tasks){
                if (i.id == id){
                    // We delete the id from the indexes list, not from the complete task list, this is to simplify the deletion process
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
            // We will view a task
            cout << "Enter the ID of the Task to be Viewed: \n";
            int id;

            // We request the user to enter the task id to be viewed
            cin >> id;
            int countIterations = 0;

            // We first compare each of the indexes list, to see if one of the indexes match the ID provided by the user
            for (int index: indexes){
                if (id == index){
                    for (Task task: tasks){
                        if (task.id == id){
                            cout << "Task View: Description: " << task.description << ". ID: " << task.id << "\n";
                            ofstream TaskFile("last_viewed_details.txt");
                            TaskFile << "Task ID: " << task.id << "\n" << "Task Description: " << task.description + "\n";
                            TaskFile.close();
                            cout << "Task details saved to file: last_viewed_details.txt" << "\n";
                        }
                    }
                }
                else {
                    countIterations++;
                }

                // The way in which we validate that the ID does not exist, is by counting the iterations through the for loop, and if in none of them the element was found, we display an error message
                if (indexes.size() == countIterations){
                    cout << "Task ID does not exist, please enter another ID." << "\n";
                    continue;
                }
            }
            continue;
        }
        cout << "You must choose between 1 and 3" << endl;
    }
    return 0;
}