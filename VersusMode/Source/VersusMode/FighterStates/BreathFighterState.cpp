// By Roberto Valentino Reynoso (RvRproduct)


#include "BreathFighterState.h"
#include "FleeFighterState.h"

#include "Kismet/GameplayStatics.h"

void BreathFighterState::SetMovement(FVector movementDirection)
{

}

void BreathFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void BreathFighterState::Enter(ABaseFighterCharacter& fighter)
{
	
}

void BreathFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	fighter.SetCurrentState(new FleeFighterState());
	fighter.GetCurrentState()->Enter(fighter);
}

void BreathFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

	if (fighter.GetActorRotation() != FRotator(0.0f, 90.0f, 90.0f))
	{

		fighter.SetActorRotation(FRotator(0.0f, 90.0f, 90.0f));
	}

	float distanceFromPlayer = fighter.GetDistanceTo(fighter.fighterManager->playerFighter);

	if (distanceFromPlayer < fighter.GetAwareOfPlayerDistance())
	{
		Exit(fighter);
		
	}
}

void BreathFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void BreathFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
