// By Roberto Valentino Reynoso (RvRproduct)


#include "BaseFighter.h"
#include "VersusMode/FighterStates/BaseFighterState.h"

BaseFighter::BaseFighter()
{
}

BaseFighter::~BaseFighter()
{
}

float BaseFighter::GetOnPlayerDistance()
{
	return onPlayerDistance;
}

FighterTypes BaseFighter::GetFighterType()
{
	return fighterType;
}

float BaseFighter::GetMaxPatrolThreshold()
{
	return maxPatrolThreshold;
}

float BaseFighter::GetCurrentPatrolThreshold()
{
	return currentPatrolThreshold;
}

float BaseFighter::GetAwareOfPlayerDistance()
{
	return awareOfPlayerDistance;
}

void BaseFighter::SetCurrentPatrolThreshold(float newPatrolThreshold)
{
	currentPatrolThreshold = newPatrolThreshold;
}

float BaseFighter::GetFighterCapsuleRadius()
{
	return fighterCapsuleRadius;
}

float BaseFighter::GetFighterCapsuleHalfHeight()
{
	return fighterCapsuleHalfHeight;
}

FCollisionShape BaseFighter::GetCachedFighterCapsuleShape()
{
	return cachedFighterCapsuleShape;
}

bool BaseFighter::GetIsOnGround()
{
	return isOnGround;
}

void BaseFighter::SetIsOnGround(bool isGrounded)
{
	isOnGround = isGrounded;
}

void BaseFighter::SetIsRunning(bool _isRunning)
{
	isRunning = _isRunning;
}

bool BaseFighter::GetIsRunning()
{
	return isRunning;
}

void BaseFighter::SetIsCreeping(bool _isCreeping)
{
	isCreeping = _isCreeping;
}

bool BaseFighter::GetIsCreeping()
{
	return isCreeping;
}

void BaseFighter::SetIsNormal(bool _isNormal)
{
	isNormal = _isNormal;
}

bool BaseFighter::GetIsNormal()
{
	return isNormal;
}

void BaseFighter::SetNumberOfAirJumps(int _currentNumberOfAirJumps)
{
	currentNumberOfAirJumps = _currentNumberOfAirJumps;
}

int BaseFighter::GetNumberOfAirJumps()
{
	return currentNumberOfAirJumps;
}

int BaseFighter::GetMaxNumberOfAirJumps()
{
	return maxNumberOfAirJumps;
}

bool BaseFighter::GetIsFacingRight()
{
	return isFacingRight;
}

void BaseFighter::SetIsFacingRight(bool facingRight)
{
	isFacingRight = facingRight;
}

bool BaseFighter::GetIsAirFacingRight()
{
	return isAirFacingRight;
}

void BaseFighter::SetIsAirFacingRight(bool _facingAirRight)
{
	isAirFacingRight = _facingAirRight;
}

bool BaseFighter::GetIsFastFalling()
{
	return isFastFalling;
}

void BaseFighter::SetIsFastFalling(bool fastFalling)
{
	isFastFalling = fastFalling;
}

float BaseFighter::GetGroundCreepSpeed()
{
	return groundCreepSpeed;
}

float BaseFighter::GetGroundWalkSpeed()
{
	return groundWalkSpeed;
}

float BaseFighter::GetGroundRunSpeed()
{
	return groundRunSpeed;
}

float BaseFighter::GetAirControlValue()
{
	return airControl;
}

void  BaseFighter::SetAirControlValue(float _airControl)
{
	airControl = _airControl;
}

float BaseFighter::GetAirSlowSpeed()
{
	return airSlowSpeed;
}

void BaseFighter::SetAirSlowSpeed(float _airSlowSpeed)
{
	airSlowSpeed = _airSlowSpeed;
}

float BaseFighter::GetAirNormalSpeed()
{
	return airNormalSpeed;
}

void BaseFighter::SetAirNormalSpeed(float _airNormalSpeed)
{
	airNormalSpeed = _airNormalSpeed;
}

float BaseFighter::GetAirFastSpeed()
{
	return airFastSpeed;
}

void BaseFighter::SetAirFastSpeed(float _airFastSpeed)
{
	airFastSpeed = _airFastSpeed;
}

float BaseFighter::GetBreathRate()
{
	return breathRate;
}

bool BaseFighter::GetIsBreathingDown()
{
	return isBreathingDown;
}

void BaseFighter::SetIsBreathingDown(bool newBreathingDown)
{
	isBreathingDown = newBreathingDown;
}

FVector BaseFighter::GetCurrentFighterVelocity()
{
	return currentFighterVelocity;
}

void BaseFighter::SetCurrentFighterVelocity(FVector newFighterVelocity)
{
	currentFighterVelocity = newFighterVelocity;
}

float BaseFighter::GetJumpHeight()
{
	return jumpHeight;
}

void BaseFighter::SetIsMoveUp(bool _isMoveUp)
{
	isMoveUp = _isMoveUp;
}

bool BaseFighter::GetIsMoveUp()
{
	return isMoveUp;
}

void BaseFighter::SetIsMoveDown(bool _isMoveDown)
{
	isMoveDown = _isMoveDown;
}

bool BaseFighter::GetIsMoveDown()
{
	return isMoveDown;
}

void BaseFighter::SetIsMoveLeft(bool _isMoveLeft)
{
	isMoveLeft = _isMoveLeft;
}

bool BaseFighter::GetIsMoveLeft()
{
	return isMoveLeft;
}

void BaseFighter::SetIsMoveRight(bool _isMoveRight)
{
	isMoveRight = _isMoveRight;
}

bool BaseFighter::GetIsMoveRight()
{
	return isMoveRight;
}

float BaseFighter::GetCurrentFighterPercent()
{
	return currentFighterPercent;
}

void BaseFighter::SetCurrentFighterPercent(float _currentFighterPercent)
{
	currentFighterPercent = _currentFighterPercent;
}

BaseFighterState* BaseFighter::GetCurrentState()
{
	return currentState;
}

void BaseFighter::SetCurrentState(BaseFighterState* newState)
{
	BaseFighterState* oldState = currentState;
	currentState = newState;
	delete oldState;
}
