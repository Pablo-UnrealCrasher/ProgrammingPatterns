#pragma once

enum struct StateNames
{
	undefined,
	standing,
	ducking,
	jumping,
	diving
};

namespace StateFunctions
{
	template<typename T>
	static StateNames ConvertToState(const T& _state)
	{
		return static_cast<StateNames>(_state);
	}

	static unsigned int GetStateId(const StateNames& _state)
	{
		return static_cast<unsigned int>(_state);
	}
}