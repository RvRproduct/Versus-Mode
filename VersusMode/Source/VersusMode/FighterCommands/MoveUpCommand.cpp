// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveUpCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/RunFighterState.h"
#include "VersusMode/FighterStates/WalkFighterState.h"
#include "VersusMode/FighterStates/AirMoveFighterState.h"
#include "VersusMode/FighterStates/FastFallFighterState.h"

void MoveUpCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{

	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->SetIsFastFalling(false);
	}
}
