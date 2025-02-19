// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveUpCommand.h"

// Fighter
#include "BaseFighter.h"

// States
#include "RunFighterState.h"
#include "WalkFighterState.h"
#include "AirMoveFighterState.h"
#include "FastFallFighterState.h"

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
