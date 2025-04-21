// By Roberto Valentino Reynoso (RvRproduct)


#include "WalkFighterState.h"
#include "RunFighterState.h"
#include "CreepFighterState.h"

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
		fighter.SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	else if (fighter.GetIsFacingRight() == true && !currentRotation.Equals(FRotator(0.0f, 0.0f, 0.0f), 0.01f)) // If Moving Right
	{
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
	if (!fighter.GetIsRunning() && !fighter.GetIsCreeping())
	{
		FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
		fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundWalkSpeed();
		fighter.AddMovementInput(fighterMoveDirection);
	}
	else if (fighter.GetIsRunning() && !fighter.GetIsCreeping())
	{
		Exit(fighter);
		fighter.SetCurrentState(new RunFighterState());
		if (fighter.GetIsFacingRight())
		{
			fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		}
		else
		{
			fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		}
		fighter.GetCurrentState()->Enter(fighter);
	}
	else
	{
		Exit(fighter);
		fighter.SetCurrentState(new CreepFighterState());
		if (fighter.GetIsFacingRight())
		{
			fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		}
		else
		{
			fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		}
		fighter.GetCurrentState()->Enter(fighter);
	}
	
}

void WalkFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void WalkFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}