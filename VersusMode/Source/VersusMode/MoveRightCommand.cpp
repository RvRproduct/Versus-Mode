// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveRightCommand.h"

// Fighter
#include "BaseFighter.h"

// States
#include "RunFighterState.h"
#include "WalkFighterState.h"
#include "AirMoveFighterState.h"

void MoveRightCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		if (fighter->GetIsRunning())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(true);
			fighter->SetCurrentState(new RunFighterState());
			fighter->GetCurrentState()->Enter(*fighter);
		}
		else
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(true);
			fighter->SetCurrentState(new WalkFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new AirMoveFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}
