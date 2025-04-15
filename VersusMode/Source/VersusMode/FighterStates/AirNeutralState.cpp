// By Roberto Valentino Reynoso (RvRproduct)


#include "AirNeutralState.h"
#include "OnGroundFighterState.h"

void AirNeutralState::SetMovement(FVector movementDirection)
{

}

void AirNeutralState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirNeutralState::Enter(ABaseFighterCharacter& fighter)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("In Air Neutral State"))
		);
	}
}

void AirNeutralState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.SetCurrentState(new OnGroundFighterState());
	fighter.GetCurrentState()->Enter(fighter);
}

void AirNeutralState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetIsOnGround())
	{
		Exit(fighter);
	}
}

void AirNeutralState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirNeutralState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}