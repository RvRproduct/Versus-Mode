// By Roberto Valentino Reynoso (RvRproduct)


#include "OnGroundFighterState.h"
#include "IdleFighterState.h"
#include "PatrolFighterState.h"
#include "BreathFighterState.h"

#include "Kismet/GameplayStatics.h"

void OnGroundFighterState::SetMovement(FVector movementDirection)
{

}

bool OnGroundFighterState::IsA(const std::type_info& type)
{
	return type == typeid(OnGroundFighterState);
}

void OnGroundFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void OnGroundFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		if (fighter.GetIsOnGround())
		{
			Exit(fighter);
		}
	}
	else if (fighter.GetFighterType() == FighterTypes::AI)
	{
		if (fighter.GetIsOnGround())
		{
			Exit(fighter);
		}
	}
	else if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		if (fighter.GetIsOnGround())
		{
			Exit(fighter);
		}
	}
}

void OnGroundFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{

		fighter.SetCurrentState(new IdleFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
	else if (fighter.GetFighterType() == FighterTypes::AI)
	{
		fighter.SetCurrentState(new PatrolFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
	else if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		fighter.SetCurrentState(new BreathFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void OnGroundFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

}

void OnGroundFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void OnGroundFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
