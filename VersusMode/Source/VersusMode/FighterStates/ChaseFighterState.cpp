// By Roberto Valentino Reynoso (RvRproduct)


#include "ChaseFighterState.h"
#include "SpinFighterState.h"
#include "PatrolFighterState.h"

void ChaseFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void ChaseFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void ChaseFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void ChaseFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void ChaseFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) < fighter.GetOnPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new SpinFighterState());
		return;
	}
	else if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) > fighter.GetAwareOfPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new PatrolFighterState());
		return;
	}

	if (fighter.fighterManager->playerFighter->GetActorLocation().X < fighter.GetActorLocation().X) // Player is on the Left
	{
		fighter.SetIsFacingRight(false);
		SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	else if (fighter.fighterManager->playerFighter->GetActorLocation().X > fighter.GetActorLocation().X) // Player is on the Right
	{
		fighter.SetIsFacingRight(true);
		SetMovement(FVector(1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}

	FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
	fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundWalkSpeed();
	fighter.AddMovementInput(fighterMoveDirection);
}

void ChaseFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void ChaseFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
