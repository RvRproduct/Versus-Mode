// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "IdleCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/IdleFighterState.h"

void IdleCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new IdleFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}
