// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FighterHud.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Hud")
	TSubclassOf<UFighterHud> FighterHudClass;

	UFighterHud* fighterHud;

	TArray<AActor*> fighters;
	FCollisionQueryParams cachedQueryParams;

	void RegisterFighter(AActor* fighter);
	void UnregisterFighter(AActor* fighter);

protected:
	virtual void BeginPlay() override;

private:
	void UpdateQueryParams();

};
