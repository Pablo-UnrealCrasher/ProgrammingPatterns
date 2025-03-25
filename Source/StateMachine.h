#pragma once

#include "State.h"
#include <vector>

struct StateTransitionTemporaryValues
{
	const unsigned int ownerState;
	const unsigned int targetState;
	bool (*evaluatingFunction)();
};

class StateMachine
{
	unsigned int currentState = -1;

	std::vector<State> states;
	std::vector<StateTransition> transitions;

	std::vector<unsigned int>* statesToInitialize = nullptr;
	std::vector<StateTransitionTemporaryValues>* transitionsToInitialize = nullptr;

public:
	StateMachine() = default;

	bool AddState(unsigned int _stateId);
	bool AddStates(std::vector<unsigned int> _stateIds);

	void AddStateTransition(const unsigned int _ownerState, const unsigned int _targetState, bool (*_evaluatingFunction)());

	bool StartStateMachine();

	unsigned int GetCurrentState() const;

	void UpdateStateMachine();
};

