// By Roberto Valentino Reynoso (RvRproduct)


#include "IdleFighterState.h"
#include "WalkFighterState.h"

void IdleFighterState::SetMovement(FVector movementDirection)
{

}

void IdleFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void IdleFighterState::Enter(ABaseFighterCharacter& fighter)
{
	
}

void IdleFighterState::Exit(ABaseFighterCharacter& fighter)
{
	if (fighter.GetIsOnGround() && fighter.GetNumberOfAirJumps() == fighter.GetMaxNumberOfAirJumps())
	{
		if (fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight())
		{
			fighter.SetIsFacingRight(false);
			fighter.SetCurrentState(new WalkFighterState());
			fighter.GetCurrentState()->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
			fighter.GetCurrentState()->Enter(fighter);
		}
		else if (!fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
		{
			fighter.SetIsFacingRight(true);
			fighter.SetCurrentState(new WalkFighterState());
			fighter.GetCurrentState()->SetMovement(FVector(1.0f, 0.0f, 0.0f));
			fighter.GetCurrentState()->Enter(fighter);
		}
	}
}

void IdleFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{
	if (fighter.GetIsOnGround() && fighter.GetNumberOfAirJumps() == fighter.GetMaxNumberOfAirJumps())
	{
		if (fighter.GetIsMoveLeft() && !fighter.GetIsMoveRight())
		{
			Exit(fighter);
		}
		else if (!fighter.GetIsMoveLeft() && fighter.GetIsMoveRight())
		{
			Exit(fighter);
		}
	}
}

void IdleFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void IdleFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
