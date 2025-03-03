// By Roberto Valentino Reynoso (RvRproduct)

// Main Header
#include "BaseFighterCharacter.h"

// Other
#include "Kismet/GameplayStatics.h"

// Fighter States
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

// Fighter Commands
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
#include "CoreMinimal.h"

// Sets default values
ABaseFighterCharacter::ABaseFighterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

// Called when the game starts or when spawned
void ABaseFighterCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (fighterManager)
	{
		fighterManager->RegisterFighter(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("FighterManager is missing in the world"));
	}

	SetStats();

	if (currentState != nullptr)
	{
		currentState->Enter(*this);
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("This is Null Sorry"))
			);
		}
	}
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
		EnhancedInputComponent->BindAction(SwitchLevelAction, ETriggerEvent::Triggered, this, &ABaseFighterCharacter::FighterSwitchLevel);
	}
}

void ABaseFighterCharacter::SetStats()
{
	// Implemented in Children
}

void ABaseFighterCharacter::FighterMove(const FInputActionValue& Value)
{
	if (fighterType != FighterTypes::Playable) { return; }

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
	if (fighterType != FighterTypes::Playable) { return; }

	bool jumpInput = Value.Get<bool>();

	if (jumpInput)
	{
		spacebar->Execute(this);
	}
}

void ABaseFighterCharacter::FighterRun(const FInputActionValue& Value)
{
	if (fighterType != FighterTypes::Playable) { return; }

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

void ABaseFighterCharacter::FighterSwitchLevel(const FInputActionValue& Value)
{
	if (fighterType != FighterTypes::Playable) { return; }

	FString LevelName = GetWorld()->GetMapName();
	FString CleanLevelName = LevelName.RightChop(GetWorld()->StreamingLevelsPrefix.Len()); // Remove prefix

	if (CleanLevelName == TEXT("MapOne"))
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("MapTwo")));
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("MapOne")));
	}
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

