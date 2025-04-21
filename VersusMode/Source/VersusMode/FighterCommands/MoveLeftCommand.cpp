// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "MoveLeftCommand.h"

#include "Kismet/GameplayStatics.h"

// Fighter
#include "VersusMode/Fighters/BaseFighter.h"

// States
#include "VersusMode/FighterStates/CreepFighterState.h"
#include "VersusMode/FighterStates/RunFighterState.h"
#include "VersusMode/FighterStates/WalkFighterState.h"
#include "VersusMode/FighterStates/AirMoveSlowFighterState.h"
#include "VersusMode/FighterStates/AirMoveNormalFighterState.h"
#include "VersusMode/FighterStates/AirMoveFastFighterState.h"

void MoveLeftCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		if (fighter->GetIsRunning() && !fighter->GetIsCreeping())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new RunFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
		else if (fighter->GetIsCreeping())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new CreepFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
		else
		{

			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new WalkFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
		
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		if (fighter->GetIsRunning() && !fighter->GetIsCreeping())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new AirMoveFastFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
		else if (fighter->GetIsCreeping())
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new AirMoveSlowFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
		else
		{
			fighter->GetCurrentState()->Exit(*fighter);
			fighter->SetIsFacingRight(false);
			fighter->SetCurrentState(new AirMoveNormalFighterState());
			fighter->GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter->GetCurrentState()->Enter(*fighter);
		}
	}
}
