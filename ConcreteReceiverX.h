#include "IReceiver.h"

class ConcreteRecieverX : public IReceiver
{
public:
    ConcreteRecieverX() = default;
    virtual void performTask() const override;
};
