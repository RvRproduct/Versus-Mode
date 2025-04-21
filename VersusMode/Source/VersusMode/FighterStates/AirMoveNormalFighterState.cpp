// By Roberto Valentino Reynoso (RvRproduct)


#include "AirMoveNormalFighterState.h"
#include "OnGroundFighterState.h"
#include "AirMoveSlowFighterState.h"
#include "AirMoveFastFighterState.h"

void AirMoveNormalFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void AirMoveNormalFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirMoveNormalFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirMoveNormalFighterState::Exit(ABaseFighterCharacter& fighter)
{

	// LOOK INTO THIS
	fighter.ConsumeMovementInputVector();

	if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void AirMoveNormalFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (!fighter.GetIsOnGround())
	{
		if (!fighter.GetIsRunning() && !fighter.GetIsCreeping())
		{
			FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
			fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetAirNormalSpeed();
			fighter.AddMovementInput(fighterMoveDirection);
		}
		else if (fighter.GetIsRunning() && !fighter.GetIsCreeping())
		{
			Exit(fighter);
			fighter.SetCurrentState(new AirMoveFastFighterState());
			if (fighter.GetIsFacingRight())
			{
				fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
			}
			else
			{
				fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			}
			fighter.GetCurrentState()->Enter(fighter);
		}
		else
		{
			Exit(fighter);
			fighter.SetCurrentState(new AirMoveSlowFighterState());
			if (fighter.GetIsFacingRight())
			{
				fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
			}
			else
			{
				fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			}
			fighter.GetCurrentState()->Enter(fighter);
		}
		
	}
	else
	{
		Exit(fighter);
	}
}

void AirMoveNormalFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirMoveNormalFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}

