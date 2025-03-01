#pragma once

#include <cstdint>

#define BUTTON_LEFT     1
#define BUTTON_MIDDLE   2
#define BUTTON_RIGHT    3
#define BUTTON_X1       4
#define BUTTON_X2       5
#define BUTTON_MASK(X)  (1u << ((X)-1))
#define BUTTON_LMASK    BUTTON_MASK(BUTTON_LEFT)
#define BUTTON_MMASK    BUTTON_MASK(BUTTON_MIDDLE)
#define BUTTON_RMASK    BUTTON_MASK(BUTTON_RIGHT)
#define BUTTON_X1MASK   BUTTON_MASK(BUTTON_X1)
#define BUTTON_X2MASK   BUTTON_MASK(BUTTON_X2)

using MouseCode = u32;
namespace Mouse {
	enum : MouseCode
	{
		ButtonLeft = BUTTON_LEFT,
		ButtonRight = BUTTON_RIGHT,
		ButtonMiddle = BUTTON_MIDDLE
	};
}
