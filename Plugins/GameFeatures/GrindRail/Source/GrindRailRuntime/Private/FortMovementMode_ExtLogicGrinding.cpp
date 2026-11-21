// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMovementMode_ExtLogicGrinding.h"

void UFortMovementMode_ExtLogicGrinding::AddGameplayCue(const FGameplayTag& GameplayCueTag)
{
}

void UFortMovementMode_ExtLogicGrinding::AddMoveIgnoreActor(ABuildingActor* BuildingActor)
{
}

bool UFortMovementMode_ExtLogicGrinding::AttemptDestroyVehicleWhileGrinding(AFortAthenaVehicle* Vehicle)
{
	return false;
}

void UFortMovementMode_ExtLogicGrinding::BeginGrinding(AFortGrindRail* GrindRail, const float OptionalStartDistance, const bool bFromInteraction)
{
}

bool UFortMovementMode_ExtLogicGrinding::CanBeginGrinding_Implementation()
{
	return false;
}

void UFortMovementMode_ExtLogicGrinding::DrawDebugHUD(AHUD* HUD, UCanvas* Canvas) const
{
}

void UFortMovementMode_ExtLogicGrinding::EndGrinding(const bool bSetEndMovementMode)
{
}

EGrindRailBoosterMode UFortMovementMode_ExtLogicGrinding::GetBoosterMode() const
{
	return EGrindRailBoosterMode();
}

void UFortMovementMode_ExtLogicGrinding::GetCameraOrientedLeanValues(const float RawLeanForward, const float RawLeanRight, float& OrientedLeanForward, float& OrientedLeanRight) const
{
}

FVector UFortMovementMode_ExtLogicGrinding::GetCurrentDirection() const
{
	return FVector();
}

float UFortMovementMode_ExtLogicGrinding::GetCurrentSpeedAlongSpline() const
{
	return float();
}

AFortGrindRail* UFortMovementMode_ExtLogicGrinding::GetGrindBaseActor() const
{
	return nullptr;
}

float UFortMovementMode_ExtLogicGrinding::GetGrindDistanceOnSpline() const
{
	return float();
}

bool UFortMovementMode_ExtLogicGrinding::GetGrindRequestJump() const
{
	return false;
}

float UFortMovementMode_ExtLogicGrinding::GetHorizontalSplineAngleDeltaDegrees() const
{
	return float();
}

float UFortMovementMode_ExtLogicGrinding::GetLeanForward() const
{
	return float();
}

float UFortMovementMode_ExtLogicGrinding::GetLeanForwardSpeedNormalized() const
{
	return float();
}

float UFortMovementMode_ExtLogicGrinding::GetLeanRight() const
{
	return float();
}

FVector UFortMovementMode_ExtLogicGrinding::GetMovementStatus() const
{
	return FVector();
}

float UFortMovementMode_ExtLogicGrinding::GetSpeedHardCap() const
{
	return float();
}

float UFortMovementMode_ExtLogicGrinding::GetValueAtLevelWithContext(const FScalableFloat& Input, float Level) const
{
	return float();
}

bool UFortMovementMode_ExtLogicGrinding::IsGrinding() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::IsSprinting() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::IsUsingFirstPersonCamera() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::IsUsingToggleSprint() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::IsWeaponActive() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::IsWeaponADS() const
{
	return false;
}

bool UFortMovementMode_ExtLogicGrinding::NativeIsShooting() const
{
	return false;
}

void UFortMovementMode_ExtLogicGrinding::OnIgnoredBuildingEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void UFortMovementMode_ExtLogicGrinding::OnJumpInput(bool bPressed)
{
}

void UFortMovementMode_ExtLogicGrinding::OnOwnerDBNO()
{
}

void UFortMovementMode_ExtLogicGrinding::OnReloadInput()
{
}

void UFortMovementMode_ExtLogicGrinding::OnRep_IsSprinting()
{
}

void UFortMovementMode_ExtLogicGrinding::OnWalkingBaseChanged(AFortPawn* Pawn, AActor* NewBase)
{
}

void UFortMovementMode_ExtLogicGrinding::PlayJumpOnSound(bool bPlayAudio)
{
}

void UFortMovementMode_ExtLogicGrinding::RemoveGameplayCue(const FGameplayTag& GameplayCueTag)
{
}

void UFortMovementMode_ExtLogicGrinding::RemoveGrindingGameplayCue(const FGameplayTag& Tag)
{
}

void UFortMovementMode_ExtLogicGrinding::RemoveMoveIgnoreActors()
{
}

void UFortMovementMode_ExtLogicGrinding::SetCurrentDirection(const FVector& NewDirection)
{
}

void UFortMovementMode_ExtLogicGrinding::SetGrindBaseActor(AFortGrindRail* NewBaseActor)
{
}

void UFortMovementMode_ExtLogicGrinding::SetGrindDistanceOnSpline(const float NewDistanceOnSpline)
{
}

void UFortMovementMode_ExtLogicGrinding::SetIsSprinting(const bool bNewIsSprinting)
{
}

void UFortMovementMode_ExtLogicGrinding::SetMovementStatus(const FVector& NewStatus)
{
}

void UFortMovementMode_ExtLogicGrinding::SphereTraceForJump(const FVector& Start, const FVector& End, float Radius, bool bDrawDebug, const FLinearColor& TraceColor, TArray<FHitResult>& OutHits) const
{
}

void UFortMovementMode_ExtLogicGrinding::TriggerEndGrinding()
{
}
