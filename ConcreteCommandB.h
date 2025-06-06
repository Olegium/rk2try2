#include "ICommand.h"
#include "IReceiver.h"

class ConcreteCommandB : public ICommand
{
public:
    ConcreteCommandB(IReceiver * receiver);
    virtual void execute() const override;

private:
    IReceiver *m_receiver;
};
