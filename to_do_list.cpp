#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Task structure
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

// Function to display the menu
void showMenu() {
    cout << "\n=== TO-DO LIST MENU ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    cout << "Enter task description: ";
    cin.ignore(); // To clear newline from previous input
    string desc;
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added.\n";
}

// Function to display tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n=== Current Tasks ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "X" : " ") << "] " << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    size_t index;
    cin >> index;

    if (index == 0 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
