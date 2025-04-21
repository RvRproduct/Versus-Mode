// By Roberto Valentino Reynoso (RvRproduct)


#include "AirNormalFighterState.h"

void AirNormalFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void AirNormalFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirNormalFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void AirNormalFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void AirNormalFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

}

void AirNormalFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirNormalFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}