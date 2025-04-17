// By Roberto Valentino Reynoso (RvRproduct)


#include "AirIdleFighterState.h"
#include "OnGroundFighterState.h"
#include "AirMoveFighterState.h"

void AirIdleFighterState::SetMovement(FVector movementDirection)
{

}

void AirIdleFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirIdleFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("In Air IDel State"))
		);
	}
}

void AirIdleFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (!fighter.GetIsOnGround())
	{
		if (fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight())
		{
			fighter.SetIsFacingRight(false);
			fighter.SetCurrentState(new AirMoveFighterState());
			fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter.GetCurrentState()->Enter(fighter);
		}
		else if (!fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
		{
			fighter.SetIsFacingRight(true);
			fighter.SetCurrentState(new AirMoveFighterState());
			fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
			fighter.GetCurrentState()->Enter(fighter);
		}
	}
	else if (fighter.GetIsOnGround())
	{
		fighter.SetCurrentState(new OnGroundFighterState());
		fighter.GetCurrentState()->Enter(fighter);
	}

}

void AirIdleFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	
	if (fighter.GetIsOnGround())
	{
		Exit(fighter);
	}
	else if (!fighter.GetIsOnGround() && fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight() ||
		!fighter.GetIsOnGround() && !fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
	{
		Exit(fighter);
	}
}

void AirIdleFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirIdleFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
