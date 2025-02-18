// By Roberto Valentino Reynoso (RvRproduct)

#include "OnGroundFighterState.h"
#include "InAirFighterState.h"
#include "IdleFighterState.h"
#include "WalkFighterState.h"
#include "RunFighterState.h"
#include "JumpFighterState.h"
#include "CrouchFighterState.h"
#include "AirMoveFighterState.h"
#include "FastFallFighterState.h"
#include "SlideFighterState.h"
#include "SuperSlideFighterState.h"

#include "TestFighter.h"

// Sets default values
ATestFighter::ATestFighter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestFighter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestFighter::SetStats()
{
	wKey = new MoveUpCommand();
	sKey = new MoveDownCommand();
	aKey = new MoveLeftCommand();
	dKey = new MoveRightCommand();
	spacebar = new JumpCommand();
	runLeft = new RunLeftCommand();
	runRight = new RunRightCommand();
	slideLeft = new SlideLeftCommand();
	slideRight = new SlideRightCommand();
	superSlideLeft = new SuperSlideLeftCommand();
	superSlideRight = new SuperSlideRightCommand();

	currentState = new OnGroundFighterState();

	jumpHeight = 100.0f;
	numberOfJumps = 8;
	weight = 4000.0f;
	groundWalkSpeed = 17.0f;
	groundRunSpeed = 36.0f;
	groundSlideRate = 40.0f;
	groundSuperSlideMultiplier = 1.5f;
	airSpeed = 250.0f;
	gravity = 7.0f;
	meterAmount = 9001.0f;
}

