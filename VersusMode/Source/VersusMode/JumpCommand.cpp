// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "JumpCommand.h"

// States
#include "GroundJumpFighterState.h"
#include "AirJumpFighterState.h"

void JumpCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new GroundJumpFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new AirJumpFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}