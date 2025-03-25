#pragma once

#include "StateTransition.h"
#include <array>

class State 
{
	const int StateId = 0;

public:
	const std::array<StateTransition*, 32> Transitions;

	State(const int _state, const std::array<StateTransition*, 32>& _arrayOfTransitions);
	State(const int _state, std::array<StateTransition*, 32>&& _arrayOfTransitions);

	inline int GetState() const;
};