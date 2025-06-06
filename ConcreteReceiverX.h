#include "IReceiver.h"

class ConcreteRecieverX : public IReciever
{
public:
    ConcreteRecieverX() = default;
    virtual void performTask() const override;
};
