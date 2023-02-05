#pragma once
#include "RealObject.h"
#include "gmock/gmock.h"  // Brings in gMock.

class MockRealObject : public  RealObject
{
public:
    MockRealObject() {
        // By default, all calls are delegated to the real object.
        ON_CALL(*this, DoWork).WillByDefault([this](int n) {
            return real_.DoWork(n);
            });

    }

    MOCK_METHOD(int, DoWork, (int));

private:
	RealObject real_;

};

class MockRealObject2 : public RealObject
{
public:

    MOCK_METHOD(int, DoWork, (int));

};