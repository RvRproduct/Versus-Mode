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
	int maxNumberOfAirJumps;
	float weight;
	FVector currentFighterVelocity;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float groundSuperSlideMultiplier;
	float airSpeed;
	float airControl;
	float gravity;
	float meterAmount;
	float maxPatrolThreshold;
	float currentPatrolThreshold;
	float awareOfPlayerDistance;
	float onPlayerDistance;

	float breathRate;

	int currentNumberOfAirJumps;
	bool isOnGround;
	bool isFacingRight;
	bool isFastFalling;
	bool isRunning;
	bool isBreathingDown;

	bool isMoveUp;
	bool isMoveDown;
	bool isMoveLeft;
	bool isMoveRight;

public:
	float GetFighterCapsuleRadius();

	float GetFighterCapsuleHalfHeight();

	FCollisionShape GetCachedFighterCapsuleShape();

	FighterTypes GetFighterType();

	// Breathing
	bool GetIsBreathingDown();

	void SetIsBreathingDown(bool newBreathingDown);

	float GetBreathRate();

	// AI
	float GetAwareOfPlayerDistance();

	float GetOnPlayerDistance();

	float GetMaxPatrolThreshold();

	float GetCurrentPatrolThreshold();

	void SetCurrentPatrolThreshold(float newPatrolThreshold);

	// Check if Player is on the Ground
	bool GetIsOnGround();

	void SetIsOnGround(bool isGrounded);

	// Running

	void SetIsRunning(bool _isRunning);

	bool GetIsRunning();

	// Is Facing Right
	bool GetIsFacingRight();

	void SetIsFacingRight(bool facingRight);

	// Is Fast Falling
	bool GetIsFastFalling();

	void SetIsFastFalling(bool fastFalling);

	// Get Ground Speeds
	float GetGroundWalkSpeed();

	float GetGroundRunSpeed();

	// Get Air Speeds
	float GetAirControlValue();

	void  SetAirControlValue(float _airControl);

	float GetAirSpeed();

	void SetAirSpeed(float _airSpeed);

	// Number of Jumps
	void SetNumberOfAirJumps(int _currentNumberOfAirJumps);

	int GetNumberOfAirJumps();

	int GetMaxNumberOfAirJumps();

	// Get Jump Height
	float GetJumpHeight();

	// Player Movement
	void SetIsMoveUp(bool _isMoveUp);

	bool GetIsMoveUp();

	void SetIsMoveDown(bool _isMoveDown);

	bool GetIsMoveDown();

	void SetIsMoveLeft(bool _isMoveLeft);

	bool GetIsMoveLeft();

	void SetIsMoveRight(bool _isMoveRight);

	bool GetIsMoveRight();

	FVector GetCurrentFighterVelocity();

	void SetCurrentFighterVelocity(FVector newFighterVelocity);

	BaseFighterState* GetCurrentState();

	void SetCurrentState(BaseFighterState* newState);

protected:
	virtual void SetStats() = 0;
};
