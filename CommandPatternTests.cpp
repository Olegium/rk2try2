#include <gtest/gtest.h>
#include "ConcreteCommandB.h"
#include "ConcreteReceiverX.h"
#include "ConcreteReceiverY.h"
#include "ConcreteCommandA.h"

#include "Invoker.h"
#include "ICommand.h"
#include "IReceiver.h"

// MockReceiver for testing commands
class MockReceiver : public IReceiver {
public:
    bool taskPerformed = false;
    void performTask() override { taskPerformed = true; }
};

// MockCommand for testing Invoker
class MockCommand : public ICommand {
public:
    bool executed = false;
    void execute() const override { executed = true; }
};

TEST(ConcreteCommandATest, ExecuteCallsReceiver) {
    MockReceiver receiver;
    ConcreteCommandA command(&receiver);
    command.execute();
    EXPECT_TRUE(receiver.taskPerformed);
}

// Test for ConcreteCommandB
TEST(ConcreteCommandBTest, ExecuteCallsReceiver) {
    MockReceiver receiver;
    ConcreteCommandB command(&receiver);
    command.execute();
    EXPECT_TRUE(receiver.taskPerformed);
}

// Test for ConcreteReceiverX
// Assuming it has a getTaskCount() method that increments with each performTask() call
TEST(ConcreteReceiverXTest, PerformTaskIncrementsCount) {
    ConcreteReceiverX receiver;
    int initialCount = IReceiver.getTaskCount();
    receiver.performTask();
    EXPECT_EQ(receiver.getTaskCount(), initialCount + 1);
}

// Test for ConcreteReceiverY
// Assuming it has a getTaskCount() method that increments with each performTask() call
TEST(ConcreteReceiverYTest, PerformTaskIncrementsCount) {
    ConcreteRecieverY receiver;
    int initialCount = IReceiver.getTaskCount();
    receiver.performTask();
    EXPECT_EQ(receiver.getTaskCount(), initialCount + 1);
}

// Test for Invoker
// Assuming it has setCommand(ICommand*) and confirm() methods
TEST(InvokerTest, ConfirmExecutesCommand) {
    MockCommand command;
    IInvoker invoker;
    IInvoker.setCommand(&command);
    invoker.confirm();
    EXPECT_TRUE(command.executed);
}
