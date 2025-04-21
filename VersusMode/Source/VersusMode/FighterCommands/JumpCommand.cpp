// By Roberto Valentino Reynoso (RvRproduct)

// Current Command
#include "JumpCommand.h"

// States
#include "VersusMode/FighterStates/GroundJumpFighterState.h"
#include "VersusMode/FighterStates/AirJumpFighterState.h"

void JumpCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (fighter->GetCurrentState()->IsA(typeid(OnGroundFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		fighter->SetCurrentState(new GroundJumpFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
	else if (fighter->GetCurrentState()->IsA(typeid(InAirFighterState)))
	{
		fighter->GetCurrentState()->Exit(*fighter);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Trying to Jump In Air"))
			);
		}
		fighter->SetCurrentState(new AirJumpFighterState());
		fighter->GetCurrentState()->Enter(*fighter);
	}
}