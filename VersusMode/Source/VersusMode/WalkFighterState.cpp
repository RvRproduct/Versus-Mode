// By Roberto Valentino Reynoso (RvRproduct)


#include "WalkFighterState.h"

#include "Kismet/GameplayStatics.h"

void WalkFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void WalkFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void WalkFighterState::Enter(ABaseFighterCharacter& fighter)
{
	
}

void WalkFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("Exit Walk"))
		);
	}
	fighter.ConsumeMovementInputVector();
}

void WalkFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	fighter.SetCurrentFighterVelocity(currentFighterMovement * fighter.GetGroundWalkSpeed());
	fighter.AddMovementInput(fighter.GetCurrentFighterVelocity());
}

void WalkFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void WalkFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}