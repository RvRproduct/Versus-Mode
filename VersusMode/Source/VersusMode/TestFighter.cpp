// By Roberto Valentino Reynoso (RvRproduct)

#include "TestFighter.h"

#include "OnGroundFighterState.h"
#include "InAirFighterState.h"
#include "IdleFighterState.h"
#include "WalkFighterState.h"
#include "RunFighterState.h"
#include "GroundJumpFighterState.h"
#include "AirJumpFighterState.h"
#include "CrouchFighterState.h"
#include "AirMoveFighterState.h"
#include "FastFallFighterState.h"
#include "SlideFighterState.h"
#include "SuperSlideFighterState.h"

#include "JumpCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "IdleCommand.h"
#include "SlideLeftCommand.h"
#include "SlideRightCommand.h"
#include "SuperSlideLeftCommand.h"
#include "SuperSlideRightCommand.h"
#include "CoreMinimal.h"

void ATestFighter::SetStats()
{
	wKey = new MoveUpCommand();
	sKey = new MoveDownCommand();
	aKey = new MoveLeftCommand();
	dKey = new MoveRightCommand();
	noKey = new IdleCommand();
	spacebar = new JumpCommand();
	slideLeft = new SlideLeftCommand();
	slideRight = new SlideRightCommand();
	superSlideLeft = new SuperSlideLeftCommand();
	superSlideRight = new SuperSlideRightCommand();

	currentState = new OnGroundFighterState();

	jumpHeight = 500.0f;
	maxNumberOfJumps = 8;
	currentNumberOfJumps = maxNumberOfJumps;
	weight = 4000.0f;
	groundWalkSpeed = 17.0f;
	groundRunSpeed = 36.0f;
	groundSlideRate = 40.0f;
	groundSuperSlideMultiplier = 1.5f;
	airSpeed = 250.0f;
	gravity = 7.0f;
	meterAmount = 9001.0f;
}



