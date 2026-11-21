// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortSpaghettiVehicle.h"
#include "Net/UnrealNetwork.h"

bool AFortSpaghettiVehicle::AimTraceHitsTarget() const
{
	return false;
}

void AFortSpaghettiVehicle::BreakTowhook()
{
}

void AFortSpaghettiVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioTowCable)
{
}

void AFortSpaghettiVehicle::CacheParticleFX(UParticleSystemComponent* InCoilTopR, UParticleSystemComponent* InCoilTopL, UParticleSystemComponent* InCoilBottomR, UParticleSystemComponent* InCoilBottomL, UParticleSystemComponent* InBoost, UParticleSystemComponent* InDust)
{
}

float AFortSpaghettiVehicle::GetAccelerationPercent() const
{
	return float();
}

bool AFortSpaghettiVehicle::GetIsExtendToggled()
{
	return false;
}

void AFortSpaghettiVehicle::GetPrimaryContact(bool& bIstouching, FVector& ContactPoint, FVector& ContactNormal) const
{
}

FVector AFortSpaghettiVehicle::GetSeatForwardDir() const
{
	return FVector();
}

FRotator AFortSpaghettiVehicle::GetSeatRotation() const
{
	return FRotator();
}

FVector AFortSpaghettiVehicle::GetSeatRotationTorque() const
{
	return FVector();
}

FVector AFortSpaghettiVehicle::GetSeatRotationVelocity() const
{
	return FVector();
}

void AFortSpaghettiVehicle::GetSeatSteerDeltas(float& SeatSteerYawDelta, float& SeatSteerPitchDelta, float& SeatSteerRollDelta)
{
}

float AFortSpaghettiVehicle::GetSeatSteerStrength() const
{
	return float();
}

FVector AFortSpaghettiVehicle::GetSeatUpDir() const
{
	return FVector();
}

FRotator AFortSpaghettiVehicle::GetShellRotation() const
{
	return FRotator();
}

FVector AFortSpaghettiVehicle::GetTargetHeading() const
{
	return FVector();
}

UPrimitiveComponent* AFortSpaghettiVehicle::GetTowhookAttachedComponent() const
{
	return nullptr;
}

FVector AFortSpaghettiVehicle::GetTowhookCableAttachLocation() const
{
	return FVector();
}

void AFortSpaghettiVehicle::GetTowhookCableEndpoints(FVector& OutCableStart, FVector& OutCableEnd) const
{
}

FVector AFortSpaghettiVehicle::GetTowhookMuzzlePosition() const
{
	return FVector();
}

FVector AFortSpaghettiVehicle::GetTowhookMuzzlePositionInterp() const
{
	return FVector();
}

FVector AFortSpaghettiVehicle::GetTowhookPosition() const
{
	return FVector();
}

FRotator AFortSpaghettiVehicle::GetTowhookRotation(const bool bInterp) const
{
	return FRotator();
}

bool AFortSpaghettiVehicle::IsTowhookAttached() const
{
	return false;
}

bool AFortSpaghettiVehicle::IsTowhookContracting() const
{
	return false;
}

bool AFortSpaghettiVehicle::IsTowhookExtending() const
{
	return false;
}

bool AFortSpaghettiVehicle::IsTowhookHolstered() const
{
	return false;
}

bool AFortSpaghettiVehicle::IsTowhookInAirExtending() const
{
	return false;
}

void AFortSpaghettiVehicle::OnBoostBounceInternal(const FVector& Location, const FVector& Normal, const float Force, UPrimitiveComponent* HitComponent)
{
}

void AFortSpaghettiVehicle::OnRep_NetTowhookAimDir()
{
}

void AFortSpaghettiVehicle::OnRep_ReplicatedAttachState()
{
}

void AFortSpaghettiVehicle::OnTowhookYankedInternal(const FVector& YankForce, UPrimitiveComponent* YankedComponent)
{
}

void AFortSpaghettiVehicle::ServerSetTowhookAttachState_Implementation(FNetTowhookAttachState InTowhookAttachState)
{
}
bool AFortSpaghettiVehicle::ServerSetTowhookAttachState_Validate(FNetTowhookAttachState InTowhookAttachState)
{
	return true;
}

void AFortSpaghettiVehicle::ServerUpdateTowhook_Implementation(FVector_NetQuantizeNormal InNetTowhookAimDir)
{
}
bool AFortSpaghettiVehicle::ServerUpdateTowhook_Validate(FVector_NetQuantizeNormal InNetTowhookAimDir)
{
	return true;
}

void AFortSpaghettiVehicle::SetTowhookAttachState(UPrimitiveComponent* Component, const FVector& WorldLocation, const FVector& WorldNormal)
{
}

void AFortSpaghettiVehicle::SetTowhookProjectile(AFortSpaghettiTowhookAttachableProjectile* ProjectileActor)
{
}

void AFortSpaghettiVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSpaghettiVehicle, ReplicatedAttachState);
	DOREPLIFETIME(AFortSpaghettiVehicle, NetTowhookAimDir);
}
