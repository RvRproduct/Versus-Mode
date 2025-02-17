// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "BaseFighter.h"
#include "GameFramework/Character.h"
#include "TestFighter.generated.h"

UCLASS()
class VERSUSMODE_API ATestFighter : public ACharacter, public BaseFighter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestFighter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetStats() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
