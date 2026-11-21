// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortProjectileBase.h"
#include "Net/UnrealNetwork.h"

void AFortProjectileBase::AddLoopingGameplayCue(const FGameplayCueTag& GameplayCueTag)
{
}

void AFortProjectileBase::AddTagToDefaultTags(FGameplayTag TagToAddToProjectileDefaultTags)
{
}

void AFortProjectileBase::EnterSkyTube(AFortSkyTube* SkyTube, bool& bIsFirstTube)
{
}

void AFortProjectileBase::ExecuteGameplayCue(const FGameplayCueTag& GameplayCueTag)
{
}

void AFortProjectileBase::ExitSkyTube(AFortSkyTube* SkyTube, bool& bIsLastTube)
{
}

float AFortProjectileBase::GetDefaultGravityScale() const
{
	return float();
}

float AFortProjectileBase::GetDefaultSpeed(float InChargePercent) const
{
	return float();
}

bool AFortProjectileBase::GetDummyProjectile_DEPRECATED()
{
	return false;
}

float AFortProjectileBase::GetGravityScale() const
{
	return float();
}

float AFortProjectileBase::GetMaxLifespan_Implementation()
{
	return float();
}

AFortPlayerController* AFortProjectileBase::GetOwnerPlayerController()
{
	return nullptr;
}

FVector AFortProjectileBase::GetOwnerVelocity_Implementation() const
{
	return FVector();
}

AFortWeapon* AFortProjectileBase::GetOwnerWeapon()
{
	return nullptr;
}

AFortSkyTube* AFortProjectileBase::GetSkyTube() const
{
	return nullptr;
}

void AFortProjectileBase::OnBounceCallback(const FHitResult& Hit, const FVector& ImpactVelocity)
{
}

void AFortProjectileBase::OnRep_CurrentSkyTube()
{
}

void AFortProjectileBase::OnRep_GravityScale()
{
}

void AFortProjectileBase::OnRep_ReplicatedMaxSpeed()
{
}

void AFortProjectileBase::OnRep_ResumeSimulationCount()
{
}

void AFortProjectileBase::OnRep_SimulationStoppingHit()
{
}

void AFortProjectileBase::OnStopCallback(const FHitResult& Hit)
{
}

void AFortProjectileBase::RemoveLoopingGameplayCue(const FGameplayCueTag& GameplayCueTag)
{
}

void AFortProjectileBase::ResumeSimulation()
{
}

void AFortProjectileBase::SetGravityScale(float InitialGravityScale)
{
}

void AFortProjectileBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortProjectileBase, ReplicatedMaxSpeed);
	DOREPLIFETIME(AFortProjectileBase, GravityScale);
	DOREPLIFETIME(AFortProjectileBase, ChargePercent);
	DOREPLIFETIME(AFortProjectileBase, SimulationStoppingHit);
	DOREPLIFETIME(AFortProjectileBase, ResumeSimulationCount);
	DOREPLIFETIME(AFortProjectileBase, SyncId);
	DOREPLIFETIME(AFortProjectileBase, CurrentSkyTube);
}

void AFortProjectileBase::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
