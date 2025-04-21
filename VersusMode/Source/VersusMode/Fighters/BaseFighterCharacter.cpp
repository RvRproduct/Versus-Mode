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

#include "VersusMode/FNormal.h"

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

	// Set all the Fighter Stats
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

	CheckIsOnGround(this);

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
		EnhancedInputComponent->BindAction(MoveActionUp, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterMoveUpPressed);
		EnhancedInputComponent->BindAction(MoveActionUp, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterMoveUpReleased);

		EnhancedInputComponent->BindAction(MoveActionDown, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterMoveDownPressed);
		EnhancedInputComponent->BindAction(MoveActionDown, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterMoveDownReleased);

		EnhancedInputComponent->BindAction(MoveActionLeft, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterMoveLeftPressed);
		EnhancedInputComponent->BindAction(MoveActionLeft, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterMoveLeftReleased);

		EnhancedInputComponent->BindAction(MoveActionRight, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterMoveRightPressed);
		EnhancedInputComponent->BindAction(MoveActionRight, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterMoveRightReleased);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterJumpPressed);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterJumpReleased);

		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterRunPressed);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterRunReleased);

		EnhancedInputComponent->BindAction(CreepAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterCreepPressed);
		EnhancedInputComponent->BindAction(CreepAction, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterCreepReleased);

		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterSlide);
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterSlide);

		EnhancedInputComponent->BindAction(SuperSlideAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterSuperSlide);

		EnhancedInputComponent->BindAction(NormalAction, ETriggerEvent::Started, this, &ABaseFighterCharacter::FighterNormalPressed);
		EnhancedInputComponent->BindAction(NormalAction, ETriggerEvent::Completed, this, &ABaseFighterCharacter::FighterNormalReleased);
	}
}

void ABaseFighterCharacter::SetStats()
{
	// Implemented in Children
}

void ABaseFighterCharacter::FighterMoveUpPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (!GetIsMoveDown())
	{
		SetIsMoveUp(true);
		wKey->Execute(this);

		
	}
	else
	{
		SetIsMoveUp(true);
	}
}

void ABaseFighterCharacter::FighterMoveDownPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (!GetIsMoveUp())
	{
		SetIsMoveDown(true);
		sKey->Execute(this);
	}
	else
	{
		SetIsMoveDown(true);
	}
}

void ABaseFighterCharacter::FighterMoveLeftPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (!GetIsMoveRight())
	{
		SetIsMoveLeft(true);
		aKey->Execute(this);
	}
	else
	{
		SetIsMoveLeft(true);
		noKey->Execute(this);
	}
}

void ABaseFighterCharacter::FighterMoveRightPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (!GetIsMoveLeft())
	{
		SetIsMoveRight(true);
		dKey->Execute(this);
	}
	else
	{
		SetIsMoveRight(true);
		noKey->Execute(this);
	}
}

void ABaseFighterCharacter::FighterMoveUpReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (GetIsMoveDown())
	{
		SetIsMoveUp(false);
		sKey->Execute(this);
	}
	else
	{
		SetIsMoveUp(false);
		CheckIfNoMovementKey();
	}

}

void ABaseFighterCharacter::FighterMoveDownReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (GetIsMoveUp())
	{
		SetIsMoveDown(false);
		wKey->Execute(this);
	}
	else
	{
		SetIsMoveDown(false);
		CheckIfNoMovementKey();
	}

}

void ABaseFighterCharacter::FighterMoveLeftReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (GetIsMoveRight())
	{
		SetIsMoveLeft(false);
		dKey->Execute(this);
	}
	else
	{
		SetIsMoveLeft(false);
		CheckIfNoMovementKey();
	}

}

void ABaseFighterCharacter::FighterMoveRightReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	if (GetIsMoveLeft())
	{
		SetIsMoveRight(false);
		aKey->Execute(this);
	}
	else
	{
		SetIsMoveRight(false);
		CheckIfNoMovementKey();
	}

}

void ABaseFighterCharacter::CheckIfNoMovementKey()
{
	if (!GetIsMoveUp() && !GetIsMoveDown() && !GetIsMoveLeft() && !GetIsMoveRight())
	{
		noKey->Execute(this);
	}
}

void ABaseFighterCharacter::FighterJumpPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	spacebar->Execute(this);
}

void ABaseFighterCharacter::FighterJumpReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }


	if (GetIsMoveLeft() && !GetIsMoveRight())
	{
		aKey->Execute(this);
	}
	else if (!GetIsMoveLeft() && GetIsMoveRight())
	{
		dKey->Execute(this);
	}
	else
	{
		CheckIfNoMovementKey();
	}
}

void ABaseFighterCharacter::FighterRunPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isRunning = true;
}

void ABaseFighterCharacter::FighterRunReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isRunning = false;
}

void ABaseFighterCharacter::FighterCreepPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isCreeping = true;
}

void ABaseFighterCharacter::FighterCreepReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isCreeping = false;
}

void ABaseFighterCharacter::FighterSlide(const FInputActionValue& Value)
{

}

void ABaseFighterCharacter::FighterSuperSlide(const FInputActionValue& Value)
{

}

void ABaseFighterCharacter::FighterNormalPressed(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isNormal = true;
	uKey->Execute(this);
}

void ABaseFighterCharacter::FighterNormalReleased(const FInputActionInstance& Instance)
{
	if (fighterType != FighterTypes::Playable) { return; }

	isNormal = false;
}


void ABaseFighterCharacter::CheckIsOnGround(ABaseFighterCharacter* fighter)
{
	float bufferBelow = 5.0f;
	TArray<FHitResult> hitResult;
	FVector start = fighter->GetActorLocation();

	FVector end = start - FVector(0, 0, bufferBelow);

	bool bHit =
		GetWorld()->SweepMultiByChannel(
			hitResult,
			start,
			end,
			FQuat::Identity,
			CollisionChannels::ECC_Ground,
			fighter->cachedFighterCapsuleShape,
			fighterManager->cachedQueryParams
		);

	fighter->SetIsOnGround(bHit);
}

