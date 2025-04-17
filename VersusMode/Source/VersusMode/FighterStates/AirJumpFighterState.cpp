// By Roberto Valentino Reynoso (RvRproduct)


#include "AirJumpFighterState.h"
#include "InAirFighterState.h"

void AirJumpFighterState::SetMovement(FVector movementDirection)
{

}

void AirJumpFighterState::HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input)
{

}

void AirJumpFighterState::Enter(ABaseFighterCharacter& fighter)
{
	if (fighter.GetNumberOfAirJumps() > 0)
	{
		if (fighter.GetFighterType() == FighterTypes::Playable)
		{
			fighter.SetNumberOfAirJumps(fighter.GetNumberOfAirJumps() - 1);
			
			fighter.LaunchCharacter(FVector(0, 0, fighter.GetJumpHeight()), true, true);
		}
	}

	Exit(fighter);
	
}

void AirJumpFighterState::Exit(ABaseFighterCharacter& fighter)
{
	fighter.SetCurrentState(new InAirFighterState());
	fighter.GetCurrentState()->Enter(fighter);
}

void AirJumpFighterState::Update(ABaseFighterCharacter& fighter, float DeltaTime)
{

}

void AirJumpFighterState::PhysicsUpdate(ABaseFighterCharacter& fighter)
{

}

void AirJumpFighterState::AnimationTriggerEvent(ABaseFighterCharacter& fighter)
{

}
