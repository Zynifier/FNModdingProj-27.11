// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortOctopusVehicle.h"
#include "Net/UnrealNetwork.h"

bool AFortOctopusVehicle::AimTraceHitsTarget() const
{
	return false;
}

void AFortOctopusVehicle::BreakTowhook()
{
}

void AFortOctopusVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioTowCable)
{
}

void AFortOctopusVehicle::CacheParticleFX(UFXSystemComponent* InCoilTopR, UFXSystemComponent* InCoilTopL, UFXSystemComponent* InCoilBottomR, UFXSystemComponent* InCoilBottomL, UFXSystemComponent* InBoost, UFXSystemComponent* InDust)
{
}

void AFortOctopusVehicle::DestroyTowhookProjectile()
{
}

float AFortOctopusVehicle::GetAccelerationPercent() const
{
	return float();
}

FRotator AFortOctopusVehicle::GetInterpedShellRotation() const
{
	return FRotator();
}

bool AFortOctopusVehicle::GetIsExtendToggled()
{
	return false;
}

void AFortOctopusVehicle::GetPrimaryContact(bool& bIstouching, FVector& ContactPoint, FVector& ContactNormal) const
{
}

FVector AFortOctopusVehicle::GetSeatForwardDir() const
{
	return FVector();
}

FRotator AFortOctopusVehicle::GetSeatRotation() const
{
	return FRotator();
}

FVector AFortOctopusVehicle::GetSeatRotationTorque() const
{
	return FVector();
}

FVector AFortOctopusVehicle::GetSeatRotationVelocity() const
{
	return FVector();
}

void AFortOctopusVehicle::GetSeatSteerDeltas(float& SeatSteerYawDelta, float& SeatSteerPitchDelta, float& SeatSteerRollDelta)
{
}

float AFortOctopusVehicle::GetSeatSteerStrength() const
{
	return float();
}

FVector AFortOctopusVehicle::GetSeatUpDir() const
{
	return FVector();
}

FRotator AFortOctopusVehicle::GetShellRotation() const
{
	return FRotator();
}

FVector AFortOctopusVehicle::GetTargetHeading() const
{
	return FVector();
}

UPrimitiveComponent* AFortOctopusVehicle::GetTowhookAttachedComponent() const
{
	return nullptr;
}

FVector AFortOctopusVehicle::GetTowhookCableAttachLocation() const
{
	return FVector();
}

void AFortOctopusVehicle::GetTowhookCableEndpoints(FVector& OutCableStart, FVector& OutCableEnd) const
{
}

FVector AFortOctopusVehicle::GetTowhookMuzzlePosition() const
{
	return FVector();
}

FVector AFortOctopusVehicle::GetTowhookMuzzlePositionInterp() const
{
	return FVector();
}

FVector AFortOctopusVehicle::GetTowhookPosition() const
{
	return FVector();
}

FRotator AFortOctopusVehicle::GetTowhookRotation(const bool bInterp) const
{
	return FRotator();
}

bool AFortOctopusVehicle::IsTowhookAttached() const
{
	return false;
}

bool AFortOctopusVehicle::IsTowhookContracting() const
{
	return false;
}

bool AFortOctopusVehicle::IsTowhookExtending() const
{
	return false;
}

bool AFortOctopusVehicle::IsTowhookHolstered() const
{
	return false;
}

bool AFortOctopusVehicle::IsTowhookInAirExtending() const
{
	return false;
}

void AFortOctopusVehicle::OnBoostBounceInternal(const FVector& Location, const FVector& Normal, const float Force, UPrimitiveComponent* HitComponent)
{
}

void AFortOctopusVehicle::OnRep_NetTowhookAimDir()
{
}

void AFortOctopusVehicle::OnRep_ReplicatedAttachState()
{
}

void AFortOctopusVehicle::OnTowhookYankedInternal(const FVector& YankForce, UPrimitiveComponent* YankedComponent)
{
}

void AFortOctopusVehicle::ServerBreakTowhook_Implementation()
{
}

void AFortOctopusVehicle::ServerSetTowhookAttachState_Implementation(FNetTowhookAttachState InTowhookAttachState)
{
}

void AFortOctopusVehicle::ServerUpdateTowhook_Implementation(FVector_NetQuantizeNormal InNetTowhookAimDir)
{
}

void AFortOctopusVehicle::SetTowhookAttachState(UPrimitiveComponent* Component, const FVector& WorldLocation, const FVector& WorldNormal)
{
}

void AFortOctopusVehicle::SetTowhookProjectile(AFortOctopusTowhookAttachableProjectile* ProjectileActor)
{
}

void AFortOctopusVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortOctopusVehicle, BaseTowhookParams);
	DOREPLIFETIME(AFortOctopusVehicle, ReplicatedAttachState);
	DOREPLIFETIME(AFortOctopusVehicle, NetTowhookAimDir);
}
