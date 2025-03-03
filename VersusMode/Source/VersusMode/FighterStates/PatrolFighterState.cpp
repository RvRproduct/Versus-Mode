// By Roberto Valentino Reynoso (RvRproduct)


#include "PatrolFighterState.h"
#include "ChaseFighterState.h"

void PatrolFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void PatrolFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void PatrolFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (fighter.GetIsFacingRight())
	{
		SetMovement(FVector(1.0f, 0.0f, 0.0f));
	}
	else
	{
		SetMovement(FVector(-1.0f, 0.0f, 0.0f));
	}

	if (fighter.GetCurrentPatrolThreshold() >= fighter.GetMaxPatrolThreshold())
	{
		fighter.SetIsFacingRight(!fighter.GetIsFacingRight());
		fighter.SetCurrentPatrolThreshold(0.0f);
	}
}

void PatrolFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.SetCurrentPatrolThreshold(0.0f);
	fighter.ConsumeMovementInputVector();
}

void PatrolFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	fighter.SetCurrentPatrolThreshold(fighter.GetCurrentPatrolThreshold() + DeltaTime);

	float distanceFromPlayer = fighter.GetDistanceTo(fighter.fighterManager->playerFighter);

	if (distanceFromPlayer < fighter.GetAwareOfPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new ChaseFighterState());
	}
	else
	{
		FRotator currentRotation = fighter.GetActorRotation();

		if (fighter.GetIsFacingRight() && !currentRotation.Equals(FRotator(0.0f, 0.0f, 0.0f), 0.01f))
		{
			SetMovement(FVector(1.0f, 0.0f, 0.0f));
			fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
		else if (!fighter.GetIsFacingRight() && !currentRotation.Equals(FRotator(0.0f, 180.0f, 0.0f), 0.01f))
		{
			SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
		}

		if (fighter.GetCurrentPatrolThreshold() >= fighter.GetMaxPatrolThreshold())
		{
			fighter.SetIsFacingRight(!fighter.GetIsFacingRight());
			fighter.SetCurrentPatrolThreshold(0.0f);
		}

		FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
		fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundWalkSpeed();
		fighter.AddMovementInput(fighterMoveDirection);
	}
}

void PatrolFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void PatrolFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
