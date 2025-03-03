// By Roberto Valentino Reynoso (RvRproduct)


#include "SpinFighterState.h"
#include "ChaseFighterState.h"

void SpinFighterState::SetMovement(FVector movementDirection)
{

}

void SpinFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void SpinFighterState::Enter(ABaseFighterCharacter& fighter)
{

}

void SpinFighterState::Exit(ABaseFighterCharacter& fighter)
{

}

void SpinFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetDistanceTo(fighter.fighterManager->playerFighter) > fighter.GetAwareOfPlayerDistance())
	{
		Exit(fighter);
		fighter.SetCurrentState(new ChaseFighterState());
	}

	fighter.AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
}

void SpinFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void SpinFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
