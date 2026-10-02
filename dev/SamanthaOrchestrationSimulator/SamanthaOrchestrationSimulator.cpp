#include <iostream>
#include "Task.h"

int main()
{
    Task testTask;

    testTask.SetName("Generate Animation");
    testTask.SetComplexity(8);
    testTask.SetStatus("Waiting");

    std::cout << "Task Name: " << testTask.GetName() << '\n';
    std::cout << "Complexity: " << testTask.GetComplexity() << '\n';
    std::cout << "Status: " << testTask.GetStatus() << '\n';

    return 0;
}