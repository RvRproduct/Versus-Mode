// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveDownCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/RunFighterState.h"
#include "VersusMode/FighterStates/WalkFighterState.h"
#include "VersusMode/FighterStates/CrouchFighterState.h"
#include "VersusMode/FighterStates/AirMoveFighterState.h"
#include "VersusMode/FighterStates/FastFallFighterState.h"

void MoveDownCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new CrouchFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetIsFastFalling(true);
		fighter->SetCurrentState(new FastFallFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}
