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
#include "FastFallCommand.h"
#include "CoreMinimal.h"

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

	SetStats();
	
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

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FighterInputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATestFighter::FighterMove);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ATestFighter::FighterJump);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ATestFighter::FighterRun);
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Triggered, this, &ATestFighter::FighterSlide);
		EnhancedInputComponent->BindAction(SuperSlideAction, ETriggerEvent::Triggered, this, &ATestFighter::FighterSuperSlide);
	}

}

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

void ATestFighter::FighterMove(const FInputActionValue& Value)
{
	FVector movementInput = Value.Get<FVector>();

	if (movementInput.X != 0 && movementInput.Y != 0)
	{
		if (movementInput.X < 0) // Left
		{

			aKey->Execute(this);
		}
		else if (movementInput.X > 0) // Right
		{
			dKey->Execute(this);
		}

		if (movementInput.Y > 0) // Up
		{
			wKey->Execute(this);
		}
		else if (movementInput.Y < 0) // Down
		{
			sKey->Execute(this);
		}
	}
	else
	{
		noKey->Execute(this);
	}
	
}

void ATestFighter::FighterJump(const FInputActionValue& Value)
{
	bool jumpInput = Value.Get<bool>();

	if (jumpInput)
	{
		spacebar->Execute(this);
	}
}

void ATestFighter::FighterRun(const FInputActionValue& Value)
{
	bool runInput = Value.Get<bool>();

	if (runInput)
	{
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void ATestFighter::FighterSlide(const FInputActionValue& Value)
{

}

void ATestFighter::FighterSuperSlide(const FInputActionValue& Value)
{

}

