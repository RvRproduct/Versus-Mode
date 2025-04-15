// By Roberto Valentino Reynoso (RvRproduct)


#include "InAirFighterState.h"
#include "AirNeutralState.h"

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

void InAirFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Trying to go to in air state"))
			);
		}

		fighter.SetCurrentState(new AirNeutralState());
		fighter.GetCurrentState()->Enter(fighter);
	}
}

void InAirFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

}

void InAirFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void InAirFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}