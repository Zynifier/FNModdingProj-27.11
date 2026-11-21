// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPawnComponent_GrindRail.h"
#include "Net/UnrealNetwork.h"

bool UFortPawnComponent_GrindRail::AddMoveIgnoreActor(ABuildingActor* BuildingActor)
{
	return false;
}

void UFortPawnComponent_GrindRail::AddTemporaryMoveIgnoreActor(ABuildingActor* BuildingActor, float IgnoreDuration)
{
}

bool UFortPawnComponent_GrindRail::AttemptDestroyVehicleWhileGrinding(AFortAthenaVehicle* Vehicle)
{
	return false;
}

void UFortPawnComponent_GrindRail::BeginGrinding(AFortGrindRail* GrindRail, const float OptionalStartDistance, const bool bFromInteraction)
{
}

bool UFortPawnComponent_GrindRail::CanBeginGrinding_Implementation()
{
	return false;
}

void UFortPawnComponent_GrindRail::DrawDebugHUD(AHUD* HUD, UCanvas* Canvas) const
{
}

void UFortPawnComponent_GrindRail::EndGrinding(const bool bSetEndMovementMode)
{
}

void UFortPawnComponent_GrindRail::GetCameraOrientedLeanValues(const float RawLeanForward, const float RawLeanRight, float& OrientedLeanForward, float& OrientedLeanRight) const
{
}

AActor* UFortPawnComponent_GrindRail::GetGrindBaseActor() const
{
	return nullptr;
}

float UFortPawnComponent_GrindRail::GetGrindDistanceOnSpline() const
{
	return float();
}

bool UFortPawnComponent_GrindRail::GetGrindRequestJump() const
{
	return false;
}

float UFortPawnComponent_GrindRail::GetHorizontalSplineAngleDeltaDegrees() const
{
	return float();
}

float UFortPawnComponent_GrindRail::GetLeanForwardSpeedNormalized() const
{
	return float();
}

FVector UFortPawnComponent_GrindRail::GetMovementStatus() const
{
	return FVector();
}

float UFortPawnComponent_GrindRail::GetSpeedHardCap() const
{
	return float();
}

bool UFortPawnComponent_GrindRail::GetWantsToGrind() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::IsGrinding() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::IsUsingFirstPersonCamera() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::IsUsingToggleSprint() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::IsWeaponActive() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::IsWeaponADS() const
{
	return false;
}

bool UFortPawnComponent_GrindRail::NativeIsShooting() const
{
	return false;
}

void UFortPawnComponent_GrindRail::OnIgnoredBuildingEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void UFortPawnComponent_GrindRail::OnJumpInput(bool bPressed)
{
}

void UFortPawnComponent_GrindRail::OnMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void UFortPawnComponent_GrindRail::OnReloadInput()
{
}

void UFortPawnComponent_GrindRail::OnRep_CurrentBoosterMode(const EGrindRailBoosterMode PreviousBoosterMode)
{
}

void UFortPawnComponent_GrindRail::OnRep_GrindingRail()
{
}

void UFortPawnComponent_GrindRail::OnRep_IsSprinting()
{
}

void UFortPawnComponent_GrindRail::OnWalkingBaseChanged(AFortPawn* Pawn, AActor* NewBase)
{
}

void UFortPawnComponent_GrindRail::RemoveMoveIgnoreActors()
{
}

void UFortPawnComponent_GrindRail::ServerBeginGrinding_Implementation(AFortGrindRail* GrindRail, const float OptionalStartDistance, const bool bFromInteraction)
{
}

void UFortPawnComponent_GrindRail::ServerUpdateWeaponHolstered_Implementation(const bool bNewHolstered, const bool bPlayEquipAnim)
{
}

void UFortPawnComponent_GrindRail::SetGrindBaseActor(AActor* NewBaseActor)
{
}

void UFortPawnComponent_GrindRail::SetGrindDistanceOnSpline(const float NewDistanceOnSpline)
{
}

void UFortPawnComponent_GrindRail::SetIsSprinting(const bool bNewIsSprinting)
{
}

void UFortPawnComponent_GrindRail::SetMovementStatus(const FVector& NewStatus)
{
}

void UFortPawnComponent_GrindRail::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, LeanForward);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, LeanRight);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, CurrentSpeedAlongSpline);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, CurrentBoosterMode);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, ReplicatedGrindingRail);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, bIsSprinting);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, bWeaponHolstered);
	DOREPLIFETIME(UFortPawnComponent_GrindRail, GoalRotation);
}
