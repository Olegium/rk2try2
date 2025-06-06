#include "IReceiver.h"

class ConcreteRecieverY : public IReceiver
{
public:
    ConcreteRecieverY() = default;
    int getTaskCount() const override;
    virtual void performTask() const override;
private:
    mutable int taskCount = 0;
};
