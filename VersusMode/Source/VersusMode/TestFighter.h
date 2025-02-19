// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "BaseFighter.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TestFighter.generated.h"

UCLASS()
class VERSUSMODE_API ATestFighter : public ACharacter, public BaseFighter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestFighter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Input Mapping")
	class UInputMappingContext* FighterInputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SlideAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SuperSlideAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetStats() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FighterMove(const FInputActionValue& Value);
	void FighterJump(const FInputActionValue& Value);
	void FighterRun(const FInputActionValue& Value);
	void FighterSlide(const FInputActionValue& Value);
	void FighterSuperSlide(const FInputActionValue& Value);

};
