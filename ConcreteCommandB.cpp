#include "ConcreteCommandB.h"

ConcreteCommandB::ConcreteCommandB(IReceiver *receiver) : m_receiver(receiver){}

void ConcreteCommandB::execute() const
{
    if (m_receiver)
    {
        m_receiver->performTask();
    }
}
