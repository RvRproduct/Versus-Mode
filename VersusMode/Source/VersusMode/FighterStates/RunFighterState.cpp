// By Roberto Valentino Reynoso (RvRproduct)


#include "RunFighterState.h"
#include "WalkFighterState.h"

void RunFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void RunFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void RunFighterState::Enter(ABaseFighterCharacter& fighter)
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

void RunFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void RunFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetIsRunning())
	{
		FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
		fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundRunSpeed();
		fighter.AddMovementInput(fighterMoveDirection);
	}
	else
	{
		Exit(fighter);
		fighter.SetCurrentState(new WalkFighterState());
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

void RunFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void RunFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}