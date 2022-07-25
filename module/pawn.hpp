// pawn.hpp
#pragma once
class _Pawn
{
private:
	union 
	{
		DEFINE_MEMBER(uint64_t, actor, 0x18); 
	};
public:
	inline auto GetActor() -> Actor { 
		return reinterpret_cast<Actor>(
			__ROL8__(this->actor - 101i64, 56)
			- 0x1C5DD825B2498B00i64
			);
	}
};