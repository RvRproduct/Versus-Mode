// By Roberto Valentino Reynoso (RvRproduct)


#include "FighterManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFighterManager::AFighterManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AFighterManager::BeginPlay()
{
	Super::BeginPlay();

	if (FighterHudClass)
	{
		fighterHud = CreateWidget<UFighterHud>(GetWorld(), FighterHudClass);
		if (fighterHud)
		{
			fighterHud->AddToViewport();
		}
	}
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
	cachedQueryParams.bFindInitialOverlaps = true;

	for (AActor* fighter : fighters)
	{
		cachedQueryParams.AddIgnoredActor(fighter);
	}
}

