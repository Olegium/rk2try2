#include "ICommand.h"
#include "IReceiver.h"

class ConcreteCommandA : public ICommand
{
public:
    ConcreteCommandA(IReceiver * receiver);
    virtual void execute() const override;

private:
    IReceiver *m_receiver;
};
