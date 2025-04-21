// By Roberto Valentino Reynoso (RvRproduct)


#include "AirMoveFastFighterState.h"
#include "OnGroundFighterState.h"
#include "AirMoveSlowFighterState.h"
#include "AirMoveNormalFighterState.h"

void AirMoveFastFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void AirMoveFastFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirMoveFastFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirMoveFastFighterState::Exit(ABaseFighterCharacter& fighter)
{

	// LOOK INTO THIS
	fighter.ConsumeMovementInputVector();

	if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void AirMoveFastFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (!fighter.GetIsOnGround())
	{
		if (fighter.GetIsRunning() && !fighter.GetIsCreeping())
		{
			FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
			fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetAirFastSpeed();
			fighter.AddMovementInput(fighterMoveDirection);
		}
		else if (fighter.GetIsCreeping())
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

void AirMoveFastFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirMoveFastFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}


