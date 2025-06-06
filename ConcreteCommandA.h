#include "ICommand.h"
#include "IReceiver.h"

class ConcreteCommandA : public ICommand
{
public:
    ConcreteCommandA(IReceiver * receiver);
    virtual void execute() const override;

public:
    IReceiver* m_receiver;
};
