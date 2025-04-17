// By Roberto Valentino Reynoso (RvRproduct)


#include "AirMoveFighterState.h"
#include "OnGroundFighterState.h"

void AirMoveFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void AirMoveFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirMoveFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirMoveFighterState::Exit(ABaseFighterCharacter& fighter)
{

	// LOOK INTO THIS
	fighter.ConsumeMovementInputVector();

	if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void AirMoveFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (!fighter.GetIsOnGround())
	{
		FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
		fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetAirSpeed();
		fighter.AddMovementInput(fighterMoveDirection);
	}
	else
	{
		Exit(fighter);
	}
}

void AirMoveFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirMoveFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
