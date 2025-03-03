// By Roberto Valentino Reynoso (RvRproduct)

#include "TestFighter.h"

#include "Components/CapsuleComponent.h"

#include "VersusMode/FighterStates/OnGroundFighterState.h"
#include "VersusMode/FighterStates/InAirFighterState.h"
#include "VersusMode/FighterStates/IdleFighterState.h"
#include "VersusMode/FighterStates/WalkFighterState.h"
#include "VersusMode/FighterStates/RunFighterState.h"
#include "VersusMode/FighterStates/GroundJumpFighterState.h"
#include "VersusMode/FighterStates/AirJumpFighterState.h"
#include "VersusMode/FighterStates/CrouchFighterState.h"
#include "VersusMode/FighterStates/AirMoveFighterState.h"
#include "VersusMode/FighterStates/FastFallFighterState.h"
#include "VersusMode/FighterStates/SlideFighterState.h"
#include "VersusMode/FighterStates/SuperSlideFighterState.h"

#include "VersusMode/FighterCommands/JumpCommand.h"
#include "VersusMode/FighterCommands/MoveLeftCommand.h"
#include "VersusMode/FighterCommands/MoveRightCommand.h"
#include "VersusMode/FighterCommands/MoveUpCommand.h"
#include "VersusMode/FighterCommands/MoveDownCommand.h"
#include "VersusMode/FighterCommands/IdleCommand.h"
#include "VersusMode/FighterCommands/SlideLeftCommand.h"
#include "VersusMode/FighterCommands/SlideRightCommand.h"
#include "VersusMode/FighterCommands/SuperSlideLeftCommand.h"
#include "VersusMode/FighterCommands/SuperSlideRightCommand.h"

ATestFighter::ATestFighter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}


void ATestFighter::SetStats()
{
	fighterType = chosenFighterType;

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

	fighterCapsuleRadius = GetCapsuleComponent()->GetUnscaledCapsuleRadius();
	fighterCapsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	cachedFighterCapsuleShape = FCollisionShape::MakeCapsule(fighterCapsuleRadius, fighterCapsuleHalfHeight);
	jumpHeight = 500.0f;
	maxNumberOfJumps = 8;
	currentNumberOfJumps = maxNumberOfJumps;
	weight = 4000.0f;
	groundWalkSpeed = 400.0f;
	groundRunSpeed = 1.0f;
	groundSlideRate = 40.0f;
	isOnGround = true;
	groundSuperSlideMultiplier = 1.5f;
	airSpeed = 250.0f;
	gravity = 7.0f;
	meterAmount = 9001.0f;
}



