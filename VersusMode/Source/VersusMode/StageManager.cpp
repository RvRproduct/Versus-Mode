// By Roberto Valentino Reynoso (RvRproduct)


#include "StageManager.h"

// Sets default values
AStageManager::AStageManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStageManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStageManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

