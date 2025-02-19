// By Roberto Valentino Reynoso (RvRproduct)

// Fighter
#include "BaseFighter.h"

// States
#include "RunFighterState.h"
#include "WalkFighterState.h"
#include "AirMoveFighterState.h"

// Current Command
#include "MoveLeftCommand.h"

class OnGroundFighterState;
class InAirFighterState;

void MoveLeftCommand::Execute(BaseFighter* fighter)
{
	if (dynamic_cast<OnGroundFighterState*>(fighter->GetCurrentState()) && fighter->GetIsRunning())
	{
		fighter->SetCurrentState(new RunFighterState());
	}
	else if (dynamic_cast<OnGroundFighterState*>(fighter->GetCurrentState()))
	{
		fighter->SetCurrentState(new WalkFighterState());
	}
	else if (dynamic_cast<InAirFighterState*>(fighter->GetCurrentState()))
	{
		fighter->SetCurrentState(new AirMoveFighterState());
	}
}
