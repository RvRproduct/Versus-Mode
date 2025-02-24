// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

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
	BaseCommand* wKey;
	BaseCommand* sKey;
	BaseCommand* aKey;
	BaseCommand* dKey;
	BaseCommand* noKey;
	BaseCommand* spacebar;
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

	int currentNumberOfJumps;
	bool isOnGround;
	bool isFacingRight;
	bool isFastFalling;
	bool isRunning;

public:
	float GetFighterCapsuleRadius();

	float GetFighterCapsuleHalfHeight();

	FCollisionShape GetCachedFighterCapsuleShape();

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
