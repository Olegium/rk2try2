#include "ConcreteCommandA.h"

ConcreteCommandA::ConcreteCommandA(IReceiver *receiver) : m_receiver(receiver){}

void ConcreteCommandA::execute() const
{
    if (m_receiver)
    {
        m_receiver->performTask();
    }
}
