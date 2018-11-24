#include <include/gmock/gmock.h>
#include <include/gtest/gtest.h>

#include "../core/include/Event.h"

using namespace testing;
using namespace ALL;

namespace ALLTesting
{
    namespace
    {
        class EventArg
        {

        };

        class EventOwner
        {
        public:
            EventOwner()
            :
            onEvent(raise_.create())
            {
            };

            void raise()
            {
                raise_(arg_);
            }

        private:
            Raise<EventArg> raise_;

        public:
            Event<EventArg>& onEvent;

            EventArg arg_;
        };
    }

    class UnitTest_Event : public testing::Test
    {
    public:
        void SetUp() override
        {

        }

        void TearDown() override
        {

        }

    public:
        EventOwner eventOwner;
    };

    TEST_F(UnitTest_Event, onEvent_add)
    {
        bool raised = false;
        auto func = std::make_shared<Event<EventArg>::callback >([&raised](EventArg) { raised = true;});

        eventOwner.onEvent += func;

        eventOwner.raise();

        EXPECT_TRUE(raised);
    }

    TEST_F(UnitTest_Event, onEvent_add_same_function)
    {
        int callCounter = 0;
        auto func = std::make_shared<Event<EventArg>::callback >([&callCounter](EventArg) { ++callCounter;});

        eventOwner.onEvent += func;

        eventOwner.onEvent += func;

        eventOwner.raise();

        EXPECT_EQ(2, callCounter);
    }

    TEST_F(UnitTest_Event, onEvent_delete_function_after_addition)
    {
        bool raised = false;
        auto func = std::make_shared<Event<EventArg>::callback >([&raised](EventArg) { raised = true;});

        eventOwner.onEvent += func;

        func = nullptr;

        eventOwner.raise();

        EXPECT_FALSE(raised);
    }

    TEST_F(UnitTest_Event, onEvent_callable)
    {
        bool raised = false;

        struct Callable
        {
            explicit Callable(bool& raised) : raised_(raised) {};

            void operator ()(EventArg arg)
            {
                raised_ = true;
            };

            bool& raised_;
        };

        Callable callable(raised);

        auto func = std::make_shared<Event<EventArg>::callback >(callable);

        eventOwner.onEvent += func;

        eventOwner.raise();

        EXPECT_TRUE(raised);
    }
}
