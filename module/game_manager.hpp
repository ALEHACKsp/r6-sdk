// game_manager.hpp
#pragma once
class _GameManager
{
private:
	union
	{
		DEFINE_MEMBER(uint64_t, entity_list, 0xB8);
		DEFINE_MEMBER(uint64_t, entity_count, 0xC0);
	};
public: 
	 auto GetEntityList() -> EntityList {
		EntityList entity_list; 
		 
		for (uint32_t idx = 0; idx < this->GetEntityCount(); idx++) { 
			entity_list.push_back(reinterpret_cast<Entity>(
				*(uintptr_t*)(											 
					_rotl64(this->entity_list, 25) + 166248590498971683  
					+ (idx * sizeof(uintptr_t)))						 
				)); 
		}
		return entity_list;
	} 
	auto GetEntity(uint32_t idx) -> Entity {
		EntityList entity_list = this->GetEntityList(); 
		return reinterpret_cast<Entity>(entity_list[idx]);
	}
	auto GetEntityCount() -> uint32_t {
		uint64_t entity_count = _rotl64(this->entity_count, 25)
			+ 166248590498971683 & 0x3FFFFFFF; 
		return static_cast<uint32_t>(entity_count & 0x3FFFFFFF);
	}  
};
auto GetGameManager() -> GameManager {
	uint64_t game_manager = ( 
		_rotl64(*(uint64_t*)((uint64_t)GetModuleHandleW(NULL) + 0x79E7100) 
			+ 0x5E8ADE5CF87BFC72, 45) - 106
		);
	return reinterpret_cast<GameManager>(game_manager);
}
 