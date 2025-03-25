#include "State.h"

State::State(const int _state, const std::array<StateTransition*, 32>& _arrayOfTransitions)
	: StateId{ _state }, Transitions { _arrayOfTransitions }
{
}

State::State(const int _state, std::array<StateTransition*, 32>&& _arrayOfTransitions)
	: StateId{ _state }, Transitions{ _arrayOfTransitions }
{
}

int State::GetState() const
{
	return StateId;
}
