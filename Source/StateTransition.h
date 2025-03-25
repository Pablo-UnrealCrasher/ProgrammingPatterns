#pragma once

#include "StateMachineMacros.h"

class State;

class StateTransition
{
	bool (*EvaluatingFunction)();

public:
	const unsigned int TargetState;

	StateTransition(const unsigned int _targetState, bool (*_evaluatingFunction)());

	inline bool EvaluateCondition() const;
};