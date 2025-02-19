// By Roberto Valentino Reynoso (RvRproduct)


#include "GroundJumpFighterState.h"

void GroundJumpFighterState::SetMovement(FVector movementDirection)
{

}

void GroundJumpFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void GroundJumpFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (fighter.GetCharacterMovement()->IsMovingOnGround())
	{

	}

	fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
}

void GroundJumpFighterState::Exit(ABaseFighterCharacter& fighter)
{

}

void GroundJumpFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetCharacterMovement()->IsMovingOnGround())
	{

	}
}

void GroundJumpFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void GroundJumpFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
