// By Roberto Valentino Reynoso (RvRproduct)


#include "AirIdleFighterState.h"
#include "OnGroundFighterState.h"
#include "AirMoveSlowFighterState.h"
#include "AirMoveNormalFighterState.h"
#include "AirMoveFastFighterState.h"

void AirIdleFighterState::SetMovement(FVector movementDirection)
{

}

void AirIdleFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirIdleFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirIdleFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (!fighter.GetIsOnGround())
	{
		if (fighter.GetIsRunning() && !fighter.GetIsCreeping())
		{
			AirMoveSpeedCheck(fighter, new AirMoveFastFighterState());
		}
		else if (fighter.GetIsCreeping())
		{
			AirMoveSpeedCheck(fighter, new AirMoveSlowFighterState());
		}
		else
		{
			AirMoveSpeedCheck(fighter, new AirMoveNormalFighterState());
		}
	}
	else if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}

}

void AirIdleFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	
	if (fighter.GetIsOnGround())
	{
		Exit(fighter);
	}
	else if (!fighter.GetIsOnGround() && fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight() ||
		!fighter.GetIsOnGround() && !fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
	{
		Exit(fighter);
	}
}

void AirIdleFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirIdleFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}


void AirIdleFighterState::AirMoveSpeedCheck(ABaseFighterCharacter& fighter, BaseFighterState* airMoveFighterState)
{
	if (fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight())
	{
		fighter.SetIsFacingRight(false);
		fighter.SetCurrentState(airMoveFighterState);
		fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		fighter.GetCurrentState()->Enter(fighter);
	}
	else if (!fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
	{
		fighter.SetIsFacingRight(true);
		fighter.SetCurrentState(airMoveFighterState);
		fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		fighter.GetCurrentState()->Enter(fighter);
	}
}
