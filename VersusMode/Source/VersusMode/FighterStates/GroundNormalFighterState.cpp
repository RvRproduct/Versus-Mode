// By Roberto Valentino Reynoso (RvRproduct)


#include "GroundNormalFighterState.h"

void GroundNormalFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void GroundNormalFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void GroundNormalFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void GroundNormalFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void GroundNormalFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

}

void GroundNormalFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void GroundNormalFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
