// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortDagwoodVehicle.h"
#include "Net/UnrealNetwork.h"

void AFortDagwoodVehicle::AddRuntimeGearsInfoOnServer(const FRuntimeGearInfo& GearInfo)
{
}

void AFortDagwoodVehicle::ApplyRuntimeModifiers()
{
}

void AFortDagwoodVehicle::CleanupLoopingPooledFX_Implementation()
{
}

bool AFortDagwoodVehicle::ForwardOrReverseInputPressed() const
{
	return false;
}

float AFortDagwoodVehicle::GetBumpiness() const
{
	return float();
}

const FDagwoodRuntimeModifiers& AFortDagwoodVehicle::GetCurrentDagwoodRuntimeProperties()
{
	static FDagwoodRuntimeModifiers Dummy;
	return Dummy;
}

float AFortDagwoodVehicle::GetMiddleAxleForwardAdjust() const
{
	return float();
}

float AFortDagwoodVehicle::GetTireHealthPercent(ETireLocations TireIndex) const
{
	return float();
}

ETireSurfaces AFortDagwoodVehicle::GetTireSurface(ETireLocations TireIndex) const
{
	return ETireSurfaces();
}

void AFortDagwoodVehicle::HandleCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

bool AFortDagwoodVehicle::IsNativeBPTickEnabled() const
{
	return false;
}

bool AFortDagwoodVehicle::IsOnLandscape() const
{
	return false;
}

bool AFortDagwoodVehicle::IsTireSkidding(const float MinSpeedForSkid, const float AngleForSkid, const float SpeedForPeelout, const float SpeedForBraking) const
{
	return false;
}

void AFortDagwoodVehicle::MakeInoperable()
{
}

void AFortDagwoodVehicle::MakeOperable(bool bAddGas)
{
}

float AFortDagwoodVehicle::NativeCalculateAccelRumbleIntensity(float MaxIntensity) const
{
	return float();
}

void AFortDagwoodVehicle::OnRep_DagwoodRuntimeModifiers(const FDagwoodRuntimeModifiers& PrevMods)
{
}

void AFortDagwoodVehicle::OnRep_FakeTires(const TArray<ETireStates>& PrevTireStates)
{
}

void AFortDagwoodVehicle::OnRep_IsInoperable()
{
}

void AFortDagwoodVehicle::OnRep_PoppedTireReaction()
{
}

void AFortDagwoodVehicle::OnRep_RandSeed()
{
}

void AFortDagwoodVehicle::OnRep_ServerRepWheelData(const TArray<FAttachedWheel>& PrevWheelData)
{
}

void AFortDagwoodVehicle::SelfDestructCleanup()
{
}

void AFortDagwoodVehicle::ServerSelfDestructActivated_Implementation()
{
}

void AFortDagwoodVehicle::ServerSetFadeDuration(const float NewFadeDuration)
{
}

void AFortDagwoodVehicle::SetDamageInfoOnServer(const bool bInDamageFriendlyVehicles, const bool bInDamageOtherVehicles, const bool bInDamageOwnVehicle, const bool bInDamageAllowedFromOtherVehicle)
{
}

void AFortDagwoodVehicle::SetRuntimeBoostInfoOnServer(const FRuntimeBoostInfo& BoostInfo)
{
}

void AFortDagwoodVehicle::SetRuntimeDriveInfoOnServer(float MaxIncline, float MaxTilt)
{
}

void AFortDagwoodVehicle::SetRuntimeFuelInfoOnServer(const FRuntimeFuelInfo& FuelInfo)
{
}

void AFortDagwoodVehicle::SetRuntimeGravityOnServer(float GravMult)
{
}

void AFortDagwoodVehicle::SetRuntimeSpringsInfoOnServer(const FRuntimeSpringsInfo& SpringsInfo)
{
}

void AFortDagwoodVehicle::SetValetAudioController(AFortValetAudioController* ValetAudio)
{
}

void AFortDagwoodVehicle::StartFade()
{
}

void AFortDagwoodVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortDagwoodVehicle, FadeDuration);
	DOREPLIFETIME(AFortDagwoodVehicle, RechargeableBoostPercent);
	DOREPLIFETIME(AFortDagwoodVehicle, DagwoodRuntimeModifiedProperties);
	DOREPLIFETIME(AFortDagwoodVehicle, ServerRepWheelData);
	DOREPLIFETIME(AFortDagwoodVehicle, FakeTireStates);
	DOREPLIFETIME(AFortDagwoodVehicle, ReplicatedPoppedTireReaction);
	DOREPLIFETIME(AFortDagwoodVehicle, bIsInoperable);
	DOREPLIFETIME(AFortDagwoodVehicle, RandomSeed);
}
