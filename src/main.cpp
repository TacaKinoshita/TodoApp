#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    tasks.push_back({description, false});
}

void viewTasks(const std::vector<Task>& tasks) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            std::cout << " [completed]";
        }
        std::cout << std::endl;
    }
}

void completeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to mark as complete: ";
    std::cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
    } else {
        std::cout << "Invalid task number!" << std::endl;
    }
    std::cin.ignore();
}

int main() {
    std::vector<Task> tasks;
    int choice;
    while (true) {
        std::cout << "1. Add Task\n2. View Tasks\n3. Complete Task\n4. Exit\nChoose an option: ";
        std::cin >> choice;
        std::cin.ignore();
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
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}
