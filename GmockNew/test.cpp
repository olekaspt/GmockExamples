#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockTurtle.h"
#include "painter.h"
#include "Game.h"
#include "MockRealObject.h"
#include "Cat.h"
#include "MockCat.h"
#include "CatGame.h"

using ::testing::InSequence;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Ge;
using ::testing::StrictMock;
using ::testing::NiceMock;

class MockTest {
public:
    MOCK_METHOD(void, SomeMethod, ());
};

/// <summary>
/// This meant to that the mock can be set up to call a 
/// non-existant method.  I Have no superclass on the 
/// MockTest and defined a method SomeMethod
/// </summary>
TEST(SomeTestCaseName, SomeTestName) {
    MockTest mock;
    EXPECT_CALL(mock, SomeMethod);
    mock.SomeMethod();

}

/// <summary>
/// This is a decent Mock test in that mock object
/// is passed to the collaborator and then we test the 
/// Painter.DrawCircle method
/// </summary>
TEST(PainterTest, CanDrawSomething) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, PenDown())
        .Times(AtLeast(1));

    Painter painter(&turtle);

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}

/// <summary>
/// This is a bad Mock test :)
/// But is meant to be show that the mock behave the
/// way we expect this.  (this is a decent UnitTest
/// for GMOCK).  Don't use this test as an pattern
/// to follow.
/// </summary>
TEST(PainterTest, TestOfExpectations) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));


    EXPECT_EQ(turtle.GetX(), 100);
    EXPECT_EQ(turtle.GetX(), 150);
    EXPECT_EQ(turtle.GetX(), 200);
    EXPECT_EQ(turtle.GetX(), 200);
    EXPECT_EQ(turtle.GetX(), 200);

    EXPECT_EQ(turtle.GetX(), 200);

    EXPECT_EQ(turtle.GetX(), 200);
    EXPECT_EQ(turtle.GetX(), 200);
}

/// <summary>
/// This basically is the same expecations in TestOfExpectations
/// but we actualy use it with a collaborator (hint this is decent
/// example to consider)
/// </summary>
TEST(PainterTest, TestChaseTurtle) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));


    Game game(&turtle);

    game.ChaseTurtle();


    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}
/// <summary>
/// This Test shows that I can setup phases of expectations
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(PainterTest, MultipleExpecations) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));


    Game game(&turtle);

    game.ChaseTurtle();

    {
        InSequence s;

        EXPECT_CALL(turtle, GetX());
        EXPECT_CALL(turtle, GetY());
        EXPECT_CALL(turtle, GoTo(5, 13));
        EXPECT_CALL(turtle, PenDown());
    }
    game.DoStuff();

    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}

/// <summary>
/// This is similiar to TestChaseTurtle
/// in that we setup expecatations that other 
/// calls will happen, and expecations on those
/// inputs (i.e. value will be greater than 80)
/// </summary>

TEST(PainterTest, TestChaseTurtleWithMoreExpectations) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));

    // Expects the turtle to move forward by 100 units.
    EXPECT_CALL(turtle, Forward( Ge( 80)  )).Times(AtLeast(1));
   
    EXPECT_CALL(turtle, GoTo(50, _)).Times(AtLeast(1));

    Game game(&turtle);

    game.ChaseTurtle();

    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}

/// <summary>
/// Using a NiceMock, we will be allowed to 
/// call ExpensiveOperation method.
/// </summary>
TEST(PainterTest, ExpensiveOperationAllowed) {
    NiceMock<MockTurtle> turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));

    // Expects the turtle to move forward by 100 units.
    EXPECT_CALL(turtle, Forward(Ge(80))).Times(AtLeast(1));

    EXPECT_CALL(turtle, GoTo(50, _)).Times(AtLeast(1));

    Game game(&turtle);

    game.ChaseTurtle();

    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}

/// <summary>
/// using a StrictMock, any thing that is called
/// that doesn't have a expecation setup will be 
/// considered an error
/// </summary>

TEST(PainterTest, ExpensiveNotOperationAllowed) {
    StrictMock<MockTurtle> turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));

    // Expects the turtle to move forward by 100 units.
    EXPECT_CALL(turtle, Forward(Ge(80))).Times(AtLeast(1));

    EXPECT_CALL(turtle, GoTo(50, _)).Times(AtLeast(1));

    EXPECT_CALL(turtle, GetY())
        .Times(8);

    Game game(&turtle);

    game.ChaseTurtle();

    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}

/// <summary>
/// The I want my cake and eat it version.  I want to 
/// be able to call whatever I want, but by setting the
/// expecation to be zero, I will error if ExpensiveOperation is called.
/// </summary>
TEST(PainterTest, ExpensiveNotOperationAllowed2) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
        .Times(8)
        .WillOnce(Return(100))
        .WillOnce(Return(150))
        .WillRepeatedly(Return(200));

    // Expects the turtle to move forward by 100 units.
    EXPECT_CALL(turtle, Forward(Ge(80))).Times(AtLeast(1));

    EXPECT_CALL(turtle, GoTo(50, _)).Times(AtLeast(1));

    EXPECT_CALL(turtle, SomeExpensiveOpertion())
        .Times(0);
    EXPECT_CALL(turtle, GetY())
        .Times(8);

    Game game(&turtle);

    game.ChaseTurtle();

    EXPECT_EQ(game.GetDogX(), 200);
    EXPECT_EQ(game.GetMoves(), 8);


}

/// <summary>
/// This is a bad example of a Mock test.
/// What this shows is show the difference between ON_CALL and EXPECT_CALL
/// </summary>
TEST(MockRealObject, MockCallsMockExpectCall) {
    MockRealObject2 mockObject;
    EXPECT_CALL(mockObject, DoWork(_))
        .Times(2)
        .WillOnce(Return(16))
        .WillOnce(Return(32));


    EXPECT_EQ(mockObject.DoWork(2), 16);
    EXPECT_EQ(mockObject.DoWork(4), 32);

}

/// <summary>
/// This is a bad example of a Mock test.
/// What this shows is show the difference between ON_CALL and EXPECT_CALL
/// </summary>
TEST(MockRealObject, MockCallsMockOnCall) {
    MockRealObject2 mockObject;
    ON_CALL(mockObject, DoWork(_))
        .WillByDefault(Return(16));


    EXPECT_EQ(mockObject.DoWork(2), 16);
    EXPECT_EQ(mockObject.DoWork(4), 16);

}
/// <summary>
/// This is a bad example of a Mock test.
/// What this shows is using a delegate to call into the real method
/// </summary>
TEST(MockRealObject, MockCallsRealThroughDelegate) {
    MockRealObject mockObject;
    EXPECT_CALL(mockObject, DoWork(_))
        .Times(2);

    // This is calling the real method
    EXPECT_EQ(mockObject.DoWork(2), 4);
    EXPECT_EQ(mockObject.DoWork(4), 8);

}

/// <summary>
/// Test where only expectations exist
/// </summary>
TEST(MockTurtle, NoSequencesRestriction) {
    MockTurtle turtle;

    EXPECT_CALL(turtle, PenDown());
    EXPECT_CALL(turtle, GetX());
    
    EXPECT_CALL(turtle, GoTo(5, 13));
    EXPECT_CALL(turtle, GetY());

    Game game(&turtle);

    game.DoStuff();

}

/// <summary>
/// Basically test NoSequencesRestriction
/// except we care in the order the calls happen
/// </summary>

TEST(MockTurtle, SequencesRestriction) {
    MockTurtle turtle;

    {
        InSequence s;

        EXPECT_CALL(turtle, GetX());
        EXPECT_CALL(turtle, GetY());
        EXPECT_CALL(turtle, GoTo(5, 13));
        EXPECT_CALL(turtle, PenDown());
    }
    Game game(&turtle);

    game.DoStuff();

}


/// <summary>
/// This testcase fails because IncreaseHappinessByAlot is non virtual and 
/// doesn't get overriden, so the Mock doesn't actually call the mocked verison of
/// SettingUpExpectationForNonVirtualMethod
/// </summary>
TEST(CatGame, SettingUpExpectationForNonVirtualMethod) {
    MockCat kitty;

    EXPECT_CALL(kitty,  IncreaseHappinessByAlot(_)).Times(1);
    EXPECT_CALL(kitty, GetHappiness()).Times(1).WillOnce(Return(50));

    CatGame p(&kitty);

    EXPECT_FALSE(p.IsHappy());
    p.Cuddle();
    // one cuddle will make a happy cat
    EXPECT_TRUE(p.IsHappy());
}

/// <summary>
/// This TestCase passes because it is using the virtual method (to contrast the example above)
/// </summary>
TEST(CatGame, SettingUpExpectationForVirtualMethod ) {
    MockCat kitty;
    EXPECT_CALL(kitty, IncreaseHappiness(_)).Times(1);
    EXPECT_CALL(kitty, GetHappiness()).Times(1).WillOnce(Return(10));

    CatGame p(&kitty);

    // only one pet does not make a happy cat
    EXPECT_FALSE(p.IsHappy());
    p.Pet();
    EXPECT_FALSE(p.IsHappy());
}


