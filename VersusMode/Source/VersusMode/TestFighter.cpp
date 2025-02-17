// By Roberto Valentino Reynoso (RvRproduct)


#include "TestFighter.h"

// Sets default values
ATestFighter::ATestFighter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestFighter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestFighter::SetStats()
{

}

