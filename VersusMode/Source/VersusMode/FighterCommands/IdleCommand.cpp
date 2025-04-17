// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "IdleCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/IdleFighterState.h"
#include "VersusMode/FighterStates/AirIdleFighterState.h"

void IdleCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new IdleFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new AirIdleFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}
