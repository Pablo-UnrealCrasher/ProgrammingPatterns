#include "StateTransition.h"
#include "State.h"

StateTransition::StateTransition(const unsigned int _targetState, bool(*_evaluatingFunction)())
	: TargetState{ _targetState }, EvaluatingFunction{ _evaluatingFunction }
{
}

inline bool StateTransition::EvaluateCondition() const
{
	return EvaluatingFunction();
}
