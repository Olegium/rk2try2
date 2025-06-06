#include <gtest/gtest.h>
#include "ConcreteCommandB.h"
#include "ConcreteReceiverX.h"
#include "ConcreteReceiverY.h"
#include "Invoker.h"
#include "ICommand.h"
#include "IReceiver.h"

// MockReceiver for testing commands
class MockReceiver : public IReceiver {
public:
    mutable bool taskPerformed = false;
    void performTask() const override { taskPerformed = true; }
};

// MockCommand for testing Invoker
class MockCommand : public ICommand {
public:
    bool executed = false;
    void execute() override { executed = true; }
};

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
    int initialCount = receiver.getTaskCount();
    receiver.performTask();
    EXPECT_EQ(receiver.getTaskCount(), initialCount + 1);
}

// Test for ConcreteReceiverY
// Assuming it has a getTaskCount() method that increments with each performTask() call
TEST(ConcreteReceiverYTest, PerformTaskIncrementsCount) {
    ConcreteReceiverY receiver;
    int initialCount = receiver.getTaskCount();
    receiver.performTask();
    EXPECT_EQ(receiver.getTaskCount(), initialCount + 1);
}

// Test for Invoker
// Assuming it has setCommand(ICommand*) and confirm() methods
TEST(InvokerTest, ConfirmExecutesCommand) {
    MockCommand command;
    Invoker invoker;
    invoker.setCommand(&command);
    invoker.confirm();
    EXPECT_TRUE(command.executed);
}
