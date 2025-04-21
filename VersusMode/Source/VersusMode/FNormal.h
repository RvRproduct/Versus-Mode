// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FNormal.generated.h"


class ABaseFighterCharacter;
class AFighterManager;

UCLASS()
class VERSUSMODE_API AFNormal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFNormal();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBox;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Owner")
	ABaseFighterCharacter* fighter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fighter Manager")
	AFighterManager* fighterManager;

	FVector offset;
	bool attackActive;
	bool isResetLocation = false;
	float maxCoolDown = 0.5f;
	float currentCoolDown = 0.0f;;
	void SetOffsetForAttack(FVector _offset);
	void SetAttackActive(bool _attackActive);
	bool GetAttackActive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
