// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FighterManager.generated.h"

UCLASS()
class VERSUSMODE_API AFighterManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFighterManager();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Fighter")
	AActor* playerFighter;

	TArray<AActor*> fighters;
	FCollisionQueryParams cachedQueryParams;

	void RegisterFighter(AActor* fighter);
	void UnregisterFighter(AActor* fighter);

private:
	void UpdateQueryParams();

};
