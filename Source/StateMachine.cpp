#include "StateMachine.h"
#include <algorithm>

static bool CheckIfVectorContainsStateId(const std::vector<unsigned int>* _existingIds, unsigned int _idToTest)
{
	for (unsigned int id : *_existingIds)
	{
		if (id == _idToTest)
		{
			return true;
		}
	}

	return false;
}

bool StateMachine::AddState(unsigned int _stateId)
{
	if (statesToInitialize == nullptr)
	{
		statesToInitialize = new std::vector<unsigned int>();
	}

	if (CheckIfVectorContainsStateId(statesToInitialize, _stateId))
	{
		return false;
	}

	statesToInitialize->push_back(_stateId);

	return true;
}

bool StateMachine::AddStates(std::vector<unsigned int> _stateIds)
{
	if (statesToInitialize == nullptr)
	{
		statesToInitialize = new std::vector<unsigned int>();
	}

	for (unsigned int newId : _stateIds)
	{
		if (CheckIfVectorContainsStateId(statesToInitialize, newId))
		{
			return false;
		}
	}

	for (unsigned int newId : _stateIds)
	{
		statesToInitialize->push_back(newId);
	}

	return true;
}

void StateMachine::AddStateTransition(const unsigned int _ownerState, const unsigned int _targetState, bool(*_evaluatingFunction)())
{
	if (transitionsToInitialize == nullptr)
	{
		transitionsToInitialize = new std::vector<StateTransitionTemporaryValues>();
	}

	transitionsToInitialize->push_back(StateTransitionTemporaryValues{ _ownerState, _targetState, _evaluatingFunction });
}

bool StateMachine::StartStateMachine()
{
	if (statesToInitialize == nullptr || transitionsToInitialize == nullptr)
	{
		if (statesToInitialize != nullptr)
		{
			delete statesToInitialize;
		}
		if (transitionsToInitialize != nullptr)
		{
			delete transitionsToInitialize;
		}

		return false;
	}

	std::sort(statesToInitialize->begin(), statesToInitialize->end());

	std::array<StateTransition*, 32> transitionsForThisState = std::array<StateTransition*, 32>(nullptr);

	for (unsigned int state : *statesToInitialize)
	{
		// Finding which transitions belong to this State.
		for (StateTransitionTemporaryValues transition : *transitionsToInitialize)
		{
			if (transition.ownerState != state)
			{
				continue;
			}

			// Finding the next space to fill within the transitions array.
			for (auto it = transitionsForThisState.begin(); it != transitionsForThisState.end(); ++it)
			{
				if (*it != nullptr)
				{
					continue;
				}

				transitions.push_back(StateTransition(transition.targetState, transition.evaluatingFunction));
				*it = &(transitions.data()[transitions.size() - 1]);
				break;
			}
		}

		states.push_back(State(state, transitionsForThisState));

		// Cleaning the buffer.
		for (auto it = transitionsForThisState.begin(); it != transitionsForThisState.end(); ++it)
		{
			*it = nullptr;
		}
	}

	delete statesToInitialize;
	delete transitionsToInitialize;

	return true;
}

unsigned int StateMachine::GetCurrentState() const
{
	return currentState;
}

void StateMachine::UpdateStateMachine()
{
	states[currentState]
}
