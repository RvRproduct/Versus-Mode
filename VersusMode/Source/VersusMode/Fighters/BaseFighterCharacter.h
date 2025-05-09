// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseFighter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "VersusMode/FighterManager.h"
#include "VersusMode/CollisionChannels.h"
#include "BaseFighterCharacter.generated.h"

class AFNormal;

UCLASS()
class VERSUSMODE_API ABaseFighterCharacter : public ACharacter, public BaseFighter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseFighterCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter ID")
	int fighterID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Attack")
	AFNormal* fighterAttack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Manager")
	AFighterManager* fighterManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Type")
	FighterTypes chosenFighterType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Input Mapping")
	class UInputMappingContext* FighterInputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> CreepAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SlideAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SuperSlideAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> NormalAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SwitchLevelAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetStats() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FighterMoveUpPressed(const FInputActionInstance& Instance);
	void FighterMoveDownPressed(const FInputActionInstance& Instance);
	void FighterMoveLeftPressed(const FInputActionInstance& Instance);
	void FighterMoveRightPressed(const FInputActionInstance& Instance);

	void FighterMoveUpReleased(const FInputActionInstance& Instance);
	void FighterMoveDownReleased(const FInputActionInstance& Instance);
	void FighterMoveLeftReleased(const FInputActionInstance& Instance);
	void FighterMoveRightReleased(const FInputActionInstance& Instance);

	void FighterJumpPressed(const FInputActionInstance& Instance);
	void FighterJumpReleased(const FInputActionInstance& Instance);

	void FighterRunPressed(const FInputActionInstance& Instance);
	void FighterRunReleased(const FInputActionInstance& Instance);

	void FighterCreepPressed(const FInputActionInstance& Instance);
	void FighterCreepReleased(const FInputActionInstance& Instance);

	void FighterSlide(const FInputActionValue& Value);
	void FighterSuperSlide(const FInputActionValue& Value);

	void FighterNormalPressed(const FInputActionInstance& Instance);
	void FighterNormalReleased(const FInputActionInstance& Instance);

	void CheckIfNoMovementKey();
	void CheckIsOnGround(ABaseFighterCharacter* fighter);

	void FighterGotHit(bool isRight)
	{
		if (isRight)
		{
			LaunchCharacter(FVector(GetCurrentFighterPercent() * 10, 0, GetJumpHeight()), true, true);
		}
		else
		{
			LaunchCharacter(FVector(GetCurrentFighterPercent() * 10 * -1, 0, GetJumpHeight()), true, true);
		}
	}
};
