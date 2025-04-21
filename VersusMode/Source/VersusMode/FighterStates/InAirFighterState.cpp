// By Roberto Valentino Reynoso (RvRproduct)


#include "InAirFighterState.h"
#include "AirIdleFighterState.h"

void InAirFighterState::SetMovement(FVector movementDirection)
{

}

bool InAirFighterState::IsA(const std::type_info& type)
{
	return type == typeid(InAirFighterState);
}

void InAirFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{
	
}

void InAirFighterState::Enter(ABaseFighterCharacter& fighter)
{
	
}

void InAirFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		fighter.SetCurrentState(new AirIdleFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void InAirFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		if (!fighter.GetIsOnGround())
		{
			Exit(fighter);
		}
		else
		{

		}
	}
}

void InAirFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void InAirFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}