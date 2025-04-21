// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fighters/BaseFighterCharacter.h"
#include "BNormal.generated.h"

UCLASS()
class VERSUSMODE_API ABNormal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABNormal();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Owner")
	ABaseFighterCharacter* fighter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
