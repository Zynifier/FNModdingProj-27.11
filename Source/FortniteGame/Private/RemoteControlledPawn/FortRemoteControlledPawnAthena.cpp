// Copyright Epic Games, Inc. All Rights Reserved.

#include "RemoteControlledPawn/FortRemoteControlledPawnAthena.h"
#include "Net/UnrealNetwork.h"

void AFortRemoteControlledPawnAthena::BeginCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

float AFortRemoteControlledPawnAthena::GetFuseLength() const
{
	return float();
}

float AFortRemoteControlledPawnAthena::GetLaunchDelay() const
{
	return float();
}

float AFortRemoteControlledPawnAthena::GetOutOfHealthExplodeDelay() const
{
	return float();
}

void AFortRemoteControlledPawnAthena::HandleControllingPlayerOutOfHealth()
{
}

bool AFortRemoteControlledPawnAthena::IsCurrentlyDelayingLaunch() const
{
	return false;
}

void AFortRemoteControlledPawnAthena::OnCapsuleTouch(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AFortRemoteControlledPawnAthena::OnClientSetupRemoteControlPawn_Implementation()
{
}

void AFortRemoteControlledPawnAthena::OnDoKill_Implementation()
{
}

void AFortRemoteControlledPawnAthena::OnRep_ControllingPlayerPawn()
{
}

void AFortRemoteControlledPawnAthena::OnRep_OverrideAbilitySystemComponent()
{
}

void AFortRemoteControlledPawnAthena::OnRep_TriggeredForDestroy()
{
}

void AFortRemoteControlledPawnAthena::OnRep_TriggeredHealthThreshold(float PreviousTriggeredHealthThreshold)
{
}

void AFortRemoteControlledPawnAthena::OnTriggeredHealthThreshold_Implementation(float PreviousTriggeredHealthThreshold, float CurrentTriggeredHealthThreshold)
{
}

void AFortRemoteControlledPawnAthena::SetupRemoteControlPawn(AFortPlayerControllerAthena* InFortPC, AFortPlayerPawnAthena* InControllingPawn, EFortCustomMovement::Type CustomMovementType, const TArray<FFortGameplayEffectContainerSpec>& EffectContainerSpecOnKill)
{
}

void AFortRemoteControlledPawnAthena::TriggerDestroyRemoteControlPawn()
{
}

void AFortRemoteControlledPawnAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, bCurrentlyDelayingLaunch);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, ServerFuseStartTime);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, RCTeam);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, ControllingPlayerPawn);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, OverrideAbilitySystemComponent);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, TriggeredHealthThreshold);
	DOREPLIFETIME(AFortRemoteControlledPawnAthena, bTriggeredForDestroy);
}
