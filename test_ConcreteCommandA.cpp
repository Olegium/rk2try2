#include <gtest/gtest.h>
#include "ConcreteCommandA.h"
#include "IReceiver.h"

class MockReceiver : public IReceiver {
public:
    bool taskPerformed = false;
    void performTask() const override { taskPerformed = true; }
};

TEST(ConcreteCommandATest, ExecuteCallsReceiver) {
    MockReceiver receiver;
    ConcreteCommandA command(&receiver);
    command.execute();
    EXPECT_TRUE(receiver.taskPerformed);
}
