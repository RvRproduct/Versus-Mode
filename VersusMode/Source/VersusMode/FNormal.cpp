// By Roberto Valentino Reynoso (RvRproduct)


#include "FNormal.h"
#include "VersusMode/Fighters/BaseFighterCharacter.h"
#include "FighterManager.h"
#include "FighterHud.h"
#include "CollisionChannels.h"

// Sets default values
AFNormal::AFNormal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	// Enable overlap
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetCollisionResponseToChannel(CollisionChannels::ECC_Ground, ECR_Ignore);
	CollisionBox->SetGenerateOverlapEvents(true);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AFNormal::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AFNormal::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (attackActive && fighter)
	{
		if (isResetLocation)
		{
			isResetLocation = false;
		}

		currentCoolDown += DeltaTime;

		if (currentCoolDown > maxCoolDown)
		{
			currentCoolDown = 0.0f;
			attackActive = false;
		}

		FVector desiredLocation = fighter->GetActorLocation() + offset;
		SetActorLocation(desiredLocation);
	}
	else
	{
		if (!isResetLocation)
		{
			SetActorLocation(fighter->GetActorLocation() + FVector(0, 0, 10000));
		}
	}
}


void AFNormal::SetOffsetForAttack(FVector _offset)
{
	offset = _offset;
	attackActive = true;
}

bool AFNormal::GetAttackActive()
{
	return attackActive;
}

void AFNormal::SetAttackActive(bool _attackActive)
{
	attackActive = _attackActive;
}

void AFNormal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != fighter)
	{
		ABaseFighterCharacter* otherFighter = Cast<ABaseFighterCharacter>(OtherActor);

		if (otherFighter)
		{
			if (fighter->GetIsOnGround())
			{
				if (fighter->GetIsFacingRight())
				{
					otherFighter->SetCurrentFighterPercent(otherFighter->GetCurrentFighterPercent() + 5.0f);
					if (otherFighter->fighterID == 1)
					{
						fighterManager->fighterHud->SetFighterOnePercent(otherFighter->GetCurrentFighterPercent());
					}
					else if (otherFighter->fighterID == 2)
					{
						fighterManager->fighterHud->SetFighterTwoPercent(otherFighter->GetCurrentFighterPercent());
					}
					
					attackActive = false;
					otherFighter->FighterGotHit(true);
				}
				else
				{
					otherFighter->SetCurrentFighterPercent(otherFighter->GetCurrentFighterPercent() + 5.0f);
					if (otherFighter->fighterID == 1)
					{
						fighterManager->fighterHud->SetFighterOnePercent(otherFighter->GetCurrentFighterPercent());
					}
					else if (otherFighter->fighterID == 2)
					{
						fighterManager->fighterHud->SetFighterTwoPercent(otherFighter->GetCurrentFighterPercent());
					}
					attackActive = false;
					otherFighter->FighterGotHit(false);
				}
			}
			else
			{
				if (fighter->GetIsAirFacingRight())
				{
					otherFighter->SetCurrentFighterPercent(otherFighter->GetCurrentFighterPercent() + 5.0f);
					if (otherFighter->fighterID == 1)
					{
						fighterManager->fighterHud->SetFighterOnePercent(otherFighter->GetCurrentFighterPercent());
					}
					else if (otherFighter->fighterID == 2)
					{
						fighterManager->fighterHud->SetFighterTwoPercent(otherFighter->GetCurrentFighterPercent());
					}
					attackActive = false;
					otherFighter->FighterGotHit(true);
				}
				else
				{
					otherFighter->SetCurrentFighterPercent(otherFighter->GetCurrentFighterPercent() + 5.0f);
					if (otherFighter->fighterID == 1)
					{
						fighterManager->fighterHud->SetFighterOnePercent(otherFighter->GetCurrentFighterPercent());
					}
					else if (otherFighter->fighterID == 2)
					{
						fighterManager->fighterHud->SetFighterTwoPercent(otherFighter->GetCurrentFighterPercent());
					}
					attackActive = false;
					otherFighter->FighterGotHit(false);
				}
			}
			
		}
	}
}
