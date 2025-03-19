#pragma once

#define GetKey(X) 0[#X]
#define IsKeyPressed(Key) (!!(GetAsyncKeyState(KEY)&0x8000)

class StateFunctions
{
public:
	template<typename T>
	static unsigned int GetStateId() 
	{
		static unsigned int id { GetNewId() };
		return id;
	}

private:
	static unsigned int GetNewId() 
	{
		static unsigned int id_count{ 0 };

		return id_count++;
	}
};