// By Roberto Valentino Reynoso (RvRproduct)


#include "GroundJumpFighterState.h"
#include "FleeFighterState.h"

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
}

void GroundJumpFighterState::Exit(ABaseFighterCharacter& fighter)
{

}

void GroundJumpFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

	if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) > fighter.GetAwareOfPlayerDistance())
		{
			Exit(fighter);
			fighter.SetCurrentState(new FleeFighterState());
		}
		else
		{
			fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
		}

	}
	else if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
	}
}

void GroundJumpFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void GroundJumpFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
