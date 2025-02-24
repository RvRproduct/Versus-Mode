// By Roberto Valentino Reynoso (RvRproduct)


#include "BaseFighter.h"
#include "BaseFighterState.h"

BaseFighter::BaseFighter()
{
}

BaseFighter::~BaseFighter()
{
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

bool BaseFighter::GetIsRunning()
{
	return isRunning;
}

bool BaseFighter::GetIsFacingRight()
{
	return isFacingRight;
}

void BaseFighter::SetIsFacingRight(bool facingRight)
{
	isFacingRight = facingRight;
}

bool BaseFighter::GetIsFastFalling()
{
	return isFastFalling;
}

void BaseFighter::SetIsFastFalling(bool fastFalling)
{
	isFastFalling = fastFalling;
}

float BaseFighter::GetGroundWalkSpeed()
{
	return groundWalkSpeed;
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
