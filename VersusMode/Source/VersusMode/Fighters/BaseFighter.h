// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

UENUM(BlueprintType)
enum class FighterTypes : uint8
{
	Playable,
	AI,
	AI2
};

class BaseFighterState;
class BaseCommand;

/**
 * 
 */
class VERSUSMODE_API BaseFighter
{
public:
	BaseFighter();
	virtual ~BaseFighter();
protected:
	FighterTypes fighterType;

	BaseCommand* wKey;
	BaseCommand* sKey;
	BaseCommand* aKey;
	BaseCommand* dKey;
	BaseCommand* noKey;
	BaseCommand* uKey;
	BaseCommand* iKey;
	BaseCommand* oKey;
	BaseCommand* pKey;
	BaseCommand* spacebar;
	BaseCommand* shift;
	BaseCommand* slideLeft;
	BaseCommand* slideRight;
	BaseCommand* superSlideLeft;
	BaseCommand* superSlideRight;

	BaseFighterState* currentState;

	float fighterCapsuleRadius;
	float fighterCapsuleHalfHeight;
	FCollisionShape cachedFighterCapsuleShape;
	float jumpHeight;
	int maxNumberOfJumps;
	float weight;
	FVector currentFighterVelocity;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float groundSuperSlideMultiplier;
	float airSpeed;
	float gravity;
	float meterAmount;
	float maxPatrolThreshold;
	float currentPatrolThreshold;
	float awareOfPlayerDistance;
	float onPlayerDistance;

	float breathRate;

	int currentNumberOfJumps;
	bool isOnGround;
	bool isFacingRight;
	bool isFastFalling;
	bool isRunning;
	bool isBreathingDown;

public:
	float GetFighterCapsuleRadius();

	float GetFighterCapsuleHalfHeight();

	FCollisionShape GetCachedFighterCapsuleShape();

	FighterTypes GetFighterType();

	bool GetIsBreathingDown();

	void SetIsBreathingDown(bool newBreathingDown);

	float GetBreathRate();

	float GetAwareOfPlayerDistance();

	float GetOnPlayerDistance();

	float GetMaxPatrolThreshold();

	float GetCurrentPatrolThreshold();

	void SetCurrentPatrolThreshold(float newPatrolThreshold);

	bool GetIsOnGround();

	void SetIsOnGround(bool isGrounded);

	bool GetIsRunning();

	bool GetIsFacingRight();

	void SetIsFacingRight(bool facingRight);

	bool GetIsFastFalling();

	void SetIsFastFalling(bool fastFalling);

	float GetGroundWalkSpeed();

	float GetJumpHeight();

	FVector GetCurrentFighterVelocity();

	void SetCurrentFighterVelocity(FVector newFighterVelocity);

	BaseFighterState* GetCurrentState();

	void SetCurrentState(BaseFighterState* newState);

protected:
	virtual void SetStats() = 0;
};
