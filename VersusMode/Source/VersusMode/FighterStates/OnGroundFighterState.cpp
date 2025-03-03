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
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("Here in OnGround"))
		);
	}

	if (fighter.GetFighterType() == FighterTypes::Playable)
	{
		if (fighter.GetIsOnGround())
		{
			Exit(fighter);
			fighter.SetCurrentState(new IdleFighterState());
		}
	}
	else if (fighter.GetFighterType() == FighterTypes::AI)
	{
		if (fighter.GetIsOnGround())
		{
			Exit(fighter);
			fighter.SetCurrentState(new PatrolFighterState());
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					5.f,
					FColor::Yellow,
					FString::Printf(TEXT("Trying to go to Patrol"))
				);
			}
		}
	}
	else if (fighter.GetFighterType() == FighterTypes::AI2)
	{
		if (fighter.GetIsOnGround())
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					5.f,
					FColor::Yellow,
					FString::Printf(TEXT("Trying to go to Breath"))
				);
			}
			Exit(fighter);
			fighter.SetCurrentState(new BreathFighterState());
		}
	}
}

void OnGroundFighterState::Exit(ABaseFighterCharacter& fighter)
{

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
