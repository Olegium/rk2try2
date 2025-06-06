#include "IReceiver.h"

class ConcreteRecieverY : public IReceiver
{
public:
    ConcreteRecieverY() = default;
    virtual void performTask() const override;
};
