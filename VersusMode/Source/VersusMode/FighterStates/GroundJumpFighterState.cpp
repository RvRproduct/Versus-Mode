// By Roberto Valentino Reynoso (RvRproduct)


#include "GroundJumpFighterState.h"
#include "FleeFighterState.h"
#include "InAirFighterState.h"

void GroundJumpFighterState::SetMovement(FVector movementDirection)
{

}

void GroundJumpFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void GroundJumpFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
		
	}
}

void GroundJumpFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		fighter.SetCurrentState(new InAirFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
	else if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		fighter.SetCurrentState(new FleeFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
	
}

void GroundJumpFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (!fighter.GetIsOnGround())
	{
		Exit(fighter);
	}
	else if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) > fighter.GetAwareOfPlayerDistance())
		{
			Exit(fighter);
		}
		else
		{
			fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
		}

	}
}

void GroundJumpFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void GroundJumpFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
