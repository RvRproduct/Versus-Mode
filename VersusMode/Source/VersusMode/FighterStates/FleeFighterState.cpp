// By Roberto Valentino Reynoso (RvRproduct)


#include "FleeFighterState.h"
#include "GroundJumpFighterState.h"
#include "BreathFighterState.h"

void FleeFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void FleeFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void FleeFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void FleeFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void FleeFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) < fighter.GetOnPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new BreathFighterState());
		return;
	}
	else if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) > fighter.GetAwareOfPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new BreathFighterState());
		return;
	}

	if (fighter.fighterManager->playerFighter->GetActorLocation().X < fighter.GetActorLocation().X) // Player is on the Left
	{
		/*fighter.SetIsFacingRight(true);
		SetMovement(FVector(1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));*/

		fighter.SetIsFacingRight(false);
		SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	else if (fighter.fighterManager->playerFighter->GetActorLocation().X > fighter.GetActorLocation().X) // Player is on the Right
	{
		/*fighter.SetIsFacingRight(false);
		SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));*/

		fighter.SetIsFacingRight(true);
		SetMovement(FVector(1.0f, 0.0f, 0.0f));
		fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}

	FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
	fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundWalkSpeed();
	fighter.AddMovementInput(fighterMoveDirection);
}

void FleeFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void FleeFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
