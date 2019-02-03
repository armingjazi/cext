#include <include/gmock/gmock.h>
#include <include/gtest/gtest.h>

#include <Event.h>

using namespace testing;
using namespace all;

namespace all
{
    namespace
    {
        class EventArg {};

        class EventArg2 {};

        class EventOwner
        {
        public:
            EventOwner()
            :
            onEvent(raise_.create()),
            onEventMultiArg(raiseMultiArg_.create())
            {
            };

            void raise()
            {
                raise_(arg_);
            }

            void raiseMultiArg()
            {
                raiseMultiArg_(arg_, arg2_);
            }

        private:
            Raise<EventArg> raise_;
            Raise<EventArg, EventArg2> raiseMultiArg_;

        public:
            IEvent<EventArg>& onEvent;
            IEvent<EventArg, EventArg2>& onEventMultiArg;

            EventArg arg_;
            EventArg2 arg2_;
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
        auto func = std::make_shared<Event<EventArg>::callback >([&raised](EventArg) { raised = true; });

        eventOwner.onEvent += func;

        eventOwner.raise();

        EXPECT_TRUE(raised);
    }

    TEST_F(UnitTest_Event, onEvent_add_multiArgument)
    {
        bool raised = false;
        auto func = std::make_shared<Event<EventArg, EventArg2>::callback >([&raised](EventArg, EventArg2) { raised = true; });

        eventOwner.onEventMultiArg += func;

        eventOwner.raiseMultiArg();

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

    TEST_F(UnitTest_Event, onEvent_callable_delete_sharedPtr)
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

        func = nullptr;

        eventOwner.raise();

        EXPECT_FALSE(raised);
    }

    TEST_F(UnitTest_Event, onEvent_add_temp_function)
    {
        int callCounter = 0;
        auto&& func = [&callCounter](EventArg) { ++callCounter;};

        eventOwner.onEvent += std::make_shared<Event<EventArg>::callback >(func);

        eventOwner.raise();

        EXPECT_EQ(0, callCounter);
    }
}
