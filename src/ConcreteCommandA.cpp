#include "ConcreteCommandA.h"

ConcreteCommandA::ConcreteCommandA(IReceiver *receiver) : m_receiever(receiver){}

void ConcreteCommandA::execute() const
{
    if (m_receiver)
    {
        m_receiver->performTask();
    }
}
