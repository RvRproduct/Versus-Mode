// By Roberto Valentino Reynoso (RvRproduct)


#include "CreepFighterState.h"
#include "RunFighterState.h"
#include "WalkFighterState.h"

void CreepFighterState::SetMovement(FVector movementDirection)
{
	currentFighterMovement = movementDirection;
}

void CreepFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void CreepFighterState::Enter(ABaseFighterCharacter& fighter)
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

void CreepFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.ConsumeMovementInputVector();
}

void CreepFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetIsCreeping())
	{
		FVector fighterMoveDirection = currentFighterMovement.GetSafeNormal();
		fighter.GetCharacterMovement()->MaxWalkSpeed = fighter.GetGroundCreepSpeed();
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

void CreepFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void CreepFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
