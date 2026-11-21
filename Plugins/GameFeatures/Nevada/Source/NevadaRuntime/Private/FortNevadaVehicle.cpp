// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortNevadaVehicle.h"
#include "Net/UnrealNetwork.h"

void AFortNevadaVehicle::AddPhysicsImpulseToTractorBeamAttachedActor(const FVector& Impulse, FName BoneName, bool bVelChange)
{
}

void AFortNevadaVehicle::DisruptTractorBeam()
{
}

void AFortNevadaVehicle::EnablePilotBubbleCollisionOnServer(bool bNewCollisionEnabled)
{
}

AFortNevadaAudioController* AFortNevadaVehicle::GetAudioController() const
{
	return nullptr;
}

float AFortNevadaVehicle::GetBatteryCharge() const
{
	return float();
}

float AFortNevadaVehicle::GetBoostChargeProgress() const
{
	return float();
}

int32 AFortNevadaVehicle::GetBoostChargesAvailable() const
{
	return int32();
}

float AFortNevadaVehicle::GetBoostChargeTimeRemaining() const
{
	return float();
}

ENevadaFlightStates AFortNevadaVehicle::GetCurrentVehicleState() const
{
	return ENevadaFlightStates();
}

void AFortNevadaVehicle::GetDriverSeatRotationAnimParams(float& OutLeftRight, float& OutForwardBack)
{
}

float AFortNevadaVehicle::GetEnergyCanonChargePercent() const
{
	return float();
}

int32 AFortNevadaVehicle::GetNumRebootsAvailable() const
{
	return int32();
}

FVector AFortNevadaVehicle::GetTractorBeamAttachLocation() const
{
	return FVector();
}

bool AFortNevadaVehicle::IsTractorBeamActive() const
{
	return false;
}

bool AFortNevadaVehicle::IsTractorBeamAttached() const
{
	return false;
}

bool AFortNevadaVehicle::IsTractorBeamDisrupted() const
{
	return false;
}

void AFortNevadaVehicle::NativeToggleCockpit(bool bEnable)
{
}

void AFortNevadaVehicle::OnAttachedActorDestroyed(AActor* DestroyedActor)
{
}

void AFortNevadaVehicle::OnAttachedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortNevadaVehicle::OnRep_NevadaState(const FNevadaState& PrevState)
{
}

void AFortNevadaVehicle::OnRep_ReplicatedTargetedActors()
{
}

void AFortNevadaVehicle::OnRep_TargetedActorChanged()
{
}

void AFortNevadaVehicle::OnRep_TractorBeamAttached()
{
}

void AFortNevadaVehicle::OnRep_TractorBeamChargeStarted()
{
}

void AFortNevadaVehicle::OnRep_TractorBeamState(const ETractorBeamState PreviousState)
{
}

void AFortNevadaVehicle::SetAttachedPawnAddedVelocity(const FVector& AddedVelocity)
{
}

void AFortNevadaVehicle::SetCannonEnabled(const bool bEnabled)
{
}

void AFortNevadaVehicle::SetTractorBeamEnabled(const bool bEnabled)
{
}

void AFortNevadaVehicle::SetTractorBeamInactive()
{
}

void AFortNevadaVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortNevadaVehicle, ServerReplicatedState);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamExtraLengthForExtents);
	DOREPLIFETIME(AFortNevadaVehicle, bTractorBeamChargeStarted);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamAttachedPrimitive);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamTargetedActors);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamAttachedActor);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamTargetedActor);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamTargetPosition);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamState);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamDeactivationTimestamp);
	DOREPLIFETIME(AFortNevadaVehicle, TractorBeamDisruptedTimestamp);
}
