// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveRightCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/RunFighterState.h"
#include "VersusMode/FighterStates/WalkFighterState.h"
#include "VersusMode/FighterStates/AirMoveFighterState.h"

void MoveRightCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		if (fighter->GetIsRunning())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(true);
			fighter->SetCurrentState(new RunFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
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
		fighter->SetIsFacingRight(true);
		fighter->SetCurrentState(new AirMoveFighterState());
		fighter->GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		fighter->GetCurrentState()->Enter(*fighter);
	}
}
