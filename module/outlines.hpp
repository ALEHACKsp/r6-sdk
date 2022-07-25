// outlines.hpp
#pragma once 
void Outlines() { 
	while (true) {  

		Sleep(1000); 

		RoundManager round_manager = GetRoundManager();
 
		if (round_manager->GetRoundState() == 3)
		{
			GameManager game_manager = GetGameManager();

			for (uint32_t idx = 0; idx < game_manager->GetEntityCount(); idx++) { 

				Entity entity = game_manager->GetEntity(idx);
				Pawn pawn = entity->GetPawn(); 
				Actor actor = pawn->GetActor();

				actor->EnableOutline();
			}
		}  
	}
}