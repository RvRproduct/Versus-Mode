// By Roberto Valentino Reynoso (RvRproduct)


#include "AirMoveSlowFighterState.h"
#include "OnGroundFighterState.h"
#include "AirMoveNormalFighterState.h"
#include "AirMoveFastFighterState.h"

void AirMoveSlowFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void AirMoveSlowFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirMoveSlowFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirMoveSlowFighterState::Exit(ABaseFighterCharacter& fighter)
{

	// LOOK INTO THIS
	fighter.ConsumeMovementInputVector();

	if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void AirMoveSlowFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (!fighter.GetIsOnGround())
	{
		if (fighter.GetIsCreeping())
		{
			FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
			fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetAirSlowSpeed();
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
			fighter.SetCurrentState(new AirMoveNormalFighterState());
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

void AirMoveSlowFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirMoveSlowFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
