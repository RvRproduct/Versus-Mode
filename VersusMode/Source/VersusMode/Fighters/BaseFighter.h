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
	float groundCreepSpeed;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float groundSuperSlideMultiplier;
	float airSlowSpeed;
	float airNormalSpeed;
	float airFastSpeed;
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
	bool isAirFacingRight;
	bool isFastFalling;

	// Used for Air and Ground
	bool isRunning;
	bool isCreeping;
	bool isBreathingDown;

	bool isMoveUp;
	bool isMoveDown;
	bool isMoveLeft;
	bool isMoveRight;

	bool isNormal;

	float currentFighterPercent;

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

	// Creep
	void SetIsCreeping(bool _isCreeping);

	bool GetIsCreeping();

	// Normal
	void SetIsNormal(bool _isNormal);

	bool GetIsNormal();

	// Is Facing Right
	bool GetIsFacingRight();

	void SetIsFacingRight(bool facingRight);

	// Is Air Facing Right
	bool GetIsAirFacingRight();

	void SetIsAirFacingRight(bool _facingAirRight);

	// Is Fast Falling
	bool GetIsFastFalling();

	void SetIsFastFalling(bool fastFalling);

	// Get Ground Speeds
	float GetGroundWalkSpeed();

	float GetGroundRunSpeed();

	float GetGroundCreepSpeed();

	// Get Air Speeds
	float GetAirControlValue();

	void  SetAirControlValue(float _airControl);

	float GetAirSlowSpeed();

	void SetAirSlowSpeed(float _airSlowSpeed);

	float GetAirNormalSpeed();

	void SetAirNormalSpeed(float _airNormalSpeed);

	float GetAirFastSpeed();

	void SetAirFastSpeed(float _airSlowSpeed);

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

	float GetCurrentFighterPercent();

	void SetCurrentFighterPercent(float _currentFighterPercent);

	FVector GetCurrentFighterVelocity();

	void SetCurrentFighterVelocity(FVector newFighterVelocity);

	BaseFighterState* GetCurrentState();

	void SetCurrentState(BaseFighterState* newState);

protected:
	virtual void SetStats() = 0;
};
