// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveDownCommand.h"

// Fighter
#include "BaseFighter.h"

// States
#include "RunFighterState.h"
#include "WalkFighterState.h"
#include "CrouchFighterState.h"
#include "AirMoveFighterState.h"
#include "FastFallFighterState.h"

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
