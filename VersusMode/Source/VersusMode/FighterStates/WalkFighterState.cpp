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
	FRotator currentRotation = fighter.GetActorRotation();

	if (fighter.GetIsFacingRight() == false && !currentRotation.Equals(FRotator(0.0f, 180.0f, 0.0f), 0.01f)) // If Moving Left
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Trying to rotate left"))
			);
		}
		fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	else if (fighter.GetIsFacingRight() == true && !currentRotation.Equals(FRotator(0.0f, 0.0f, 0.0f), 0.01f)) // If Moving Right
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Trying to rotate right"))
			);
		}

		fighter.SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
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
	FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
	fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundWalkSpeed();
	fighter.AddMovementInput(fighterMoveDirection);
}

void WalkFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void WalkFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}