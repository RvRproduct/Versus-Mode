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

	static AFighterManager* GetInstance(UWorld* world);
	TArray<AActor*> fighters;
	FCollisionQueryParams cachedQueryParams;

	void RegisterFighter(AActor* fighter);
	void UnregisterFighter(AActor* fighter);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	static AFighterManager* Instance;

	void UpdateQueryParams();

};
