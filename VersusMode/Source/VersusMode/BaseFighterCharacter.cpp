// By Roberto Valentino Reynoso (RvRproduct)

// Main Header
#include "BaseFighterCharacter.h"

// Other
#include "Kismet/GameplayStatics.h"

// Fighter States
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

// Fighter Commands
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

// Sets default values
ABaseFighterCharacter::ABaseFighterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseFighterCharacter::BeginPlay()
{
	Super::BeginPlay();

	fighterManager = AFighterManager::GetInstance(GetWorld());
	if (fighterManager)
	{
		fighterManager->RegisterFighter(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("FighterManager is missing in the world"));
	}

	SetStats();
}

// Called every frame
void ABaseFighterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentState != nullptr)
	{
		currentState->Update(*this, DeltaTime);
	}
}

// Called to bind functionality to input
void ABaseFighterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
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
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterMove);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterJump);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterRun);
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterSlide);
		EnhancedInputComponent->BindAction(SuperSlideAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterSuperSlide);
	}
}

void ABaseFighterCharacter::SetStats()
{
	// Implemented in Children
}

void ABaseFighterCharacter::FighterMove(const FInputActionValue& Value)
{
	FVector movementInput = Value.Get<FVector>();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("Hit Move Key"))
		);
	}

	if (movementInput.X != 0 || movementInput.Y != 0)
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
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Trying to go to idle"))
			);
		}
		noKey->Execute(this);
	}

}

void ABaseFighterCharacter::FighterJump(const FInputActionValue& Value)
{
	bool jumpInput = Value.Get<bool>();

	if (jumpInput)
	{
		spacebar->Execute(this);
	}
}

void ABaseFighterCharacter::FighterRun(const FInputActionValue& Value)
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

void ABaseFighterCharacter::FighterSlide(const FInputActionValue& Value)
{

}

void ABaseFighterCharacter::FighterSuperSlide(const FInputActionValue& Value)
{

}

void ABaseFighterCharacter::CheckIsOnGround(ABaseFighterCharacter* fighter)
{
	FHitResult hitResult;
	FVector start = fighter->GetActorLocation();
	FVector end = start - FVector(0, 0, 10);

	fighter->SetIsOnGround(
		GetWorld()->SweepSingleByChannel(
			hitResult,
			start,
			end,
			FQuat::Identity,
			ECC_Pawn,
			fighter->cachedFighterCapsuleShape,
			fighterManager->cachedQueryParams
		)
	);
}

