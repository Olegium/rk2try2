#pragma once

class IReceiver
{
public:
    virtual ~IReceiver() {}
    virtual void performTask() const = 0;
};
