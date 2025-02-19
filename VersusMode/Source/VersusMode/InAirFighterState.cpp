// By Roberto Valentino Reynoso (RvRproduct)


#include "InAirFighterState.h"

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