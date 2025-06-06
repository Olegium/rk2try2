#pragma once

class IReceiver
{
public:
    virtual ~IReceiver() = default;
    virtual void performTask() const = 0;
};
