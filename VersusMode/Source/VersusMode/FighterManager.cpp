// By Roberto Valentino Reynoso (RvRproduct)


#include "FighterManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AFighterManager* AFighterManager::Instance = nullptr;

// Sets default values
AFighterManager::AFighterManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (Instance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Warning: Another FighterManager instance exists! Destroying Duplicate."));
		Destroy();
	}
	else
	{
		Instance = this;
	}

}

// Called when the game starts or when spawned
void AFighterManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFighterManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFighterManager::RegisterFighter(AActor* fighter)
{
	if (!fighters.Contains(fighter))
	{
		fighters.Add(fighter);
		UpdateQueryParams();
	}
}

void AFighterManager::UnregisterFighter(AActor* fighter)
{
	if (fighters.Contains(fighter))
	{
		fighters.Remove(fighter);
		UpdateQueryParams();
	}
}

void AFighterManager::UpdateQueryParams()
{
	cachedQueryParams = FCollisionQueryParams();

	for (AActor* fighter : fighters)
	{
		cachedQueryParams.AddIgnoredActor(fighter);
	}
}

AFighterManager* AFighterManager::GetInstance(UWorld* world)
{
	if (!Instance)
	{
		Instance = Cast<AFighterManager>(UGameplayStatics::GetActorOfClass(world, AFighterManager::StaticClass()));

		if (!Instance)
		{
			// There is no Fighter Manager
			UE_LOG(LogTemp, Error, TEXT("FighterManager is missing in the world"));
		}
	}

	return Instance;
}

