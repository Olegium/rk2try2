#include "ConcreteReceiverY.h"

#include <iostream>

void ConcreteRecieverY::performTask() const
{
    std::cout << "Performing task Y" << std::endl;
}
void ConcreteRecieverY::performTask() const {
    taskCount++; // Increment the count
}

int ConcreteRecieverY::getTaskCount() const {
    return taskCount;
}
