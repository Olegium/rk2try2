#include "ICommand.h"
#include "IReceiver.h"

class ConcreteCommandA : public ICommand
{
public:
    ConcreteCommandA(IReciever * reciever);
    virtual void execute() const override;

private:
    IReciever *m_reciever;
};
