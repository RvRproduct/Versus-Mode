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
#include "VersusMode/FighterCommands/NormalCommand.h"
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
	uKey = new NormalCommand();
	noKey = new IdleCommand();
	spacebar = new JumpCommand();
	slideLeft = new SlideLeftCommand();
	slideRight = new SlideRightCommand();
	superSlideLeft = new SuperSlideLeftCommand();
	superSlideRight = new SuperSlideRightCommand();

	currentState = new OnGroundFighterState();

	fighterCapsuleRadius = GetCapsuleComponent()->GetScaledCapsuleRadius();
	fighterCapsuleHalfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	cachedFighterCapsuleShape = FCollisionShape::MakeCapsule(fighterCapsuleRadius, fighterCapsuleHalfHeight);
	jumpHeight = 500.0f;
	maxNumberOfAirJumps = 2;
	currentNumberOfAirJumps = maxNumberOfAirJumps;
	weight = 4000.0f;
	groundCreepSpeed = 200.0f;
	groundWalkSpeed = 400.0f;
	groundRunSpeed = 800.0f;
	groundSlideRate = 40.0f;
	airSlowSpeed = 200.0f;
	airNormalSpeed = 400.0f;
	airFastSpeed = 800.0f;
	airControl = 1.0f;
	isOnGround = true;
	isMoveUp = false;
	isMoveDown = false;
	isMoveLeft = false;
	isMoveRight = false;
	groundSuperSlideMultiplier = 1.5f;
	gravity = 7.0f;
	meterAmount = 9001.0f;

	// Make Sure Air Control is Set
	GetCharacterMovement()->AirControl = GetAirControlValue();
}



