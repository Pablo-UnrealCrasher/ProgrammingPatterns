#pragma once

#include "StateFunctions.h"

class State 
{
public:
	State() = default;

	virtual void Execute();

	/// <summary>
	/// Updates the system based on the input added.
	/// </summary>
	/// <param name="_input"></param>
	/// <returns></returns>
	virtual int EnterInput(const char _input);

protected:
	virtual void DefaultInit();
	virtual void DefaultShutDown();
	virtual void EnterState(const State& _otherState);
	virtual void ExitState();
};