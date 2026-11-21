// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortCharacterVehicle_Ostrich.h"
#include "Net/UnrealNetwork.h"

void AFortCharacterVehicle_Ostrich::AirDash(const FVector& InDirection, float Speed, float MinVerticalSpeed)
{
}

void AFortCharacterVehicle_Ostrich::ForceDetonate(bool bExplode)
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_Fire_Single(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_Fire_Start()
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_Fire_Stop()
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_Load()
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_LoadSingleRocket(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void AFortCharacterVehicle_Ostrich::GameplayCue_Athena_Ostrich_Reload()
{
}

FVector AFortCharacterVehicle_Ostrich::GetAimPoint() const
{
	return FVector();
}

bool AFortCharacterVehicle_Ostrich::GetDashAnimationActive() const
{
	return false;
}

float AFortCharacterVehicle_Ostrich::GetDriverTurnAngleDelta() const
{
	return float();
}

float AFortCharacterVehicle_Ostrich::GetGunnerAimAngleDelta() const
{
	return float();
}

AFortWeaponRanged_Ostrich* AFortCharacterVehicle_Ostrich::GetGunnerWeapon()
{
	return nullptr;
}

bool AFortCharacterVehicle_Ostrich::GetIsChargingJump() const
{
	return false;
}

bool AFortCharacterVehicle_Ostrich::GetIsDashing() const
{
	return false;
}

float AFortCharacterVehicle_Ostrich::GetJumpChargeCursor() const
{
	return float();
}

UFortAnimWorldStriderComponent* AFortCharacterVehicle_Ostrich::GetWorldStriderComponent()
{
	return nullptr;
}

bool AFortCharacterVehicle_Ostrich::IsFiringRockets() const
{
	return false;
}

bool AFortCharacterVehicle_Ostrich::IsRocketOnCooldown() const
{
	return false;
}

bool AFortCharacterVehicle_Ostrich::IsShotgunReloading() const
{
	return false;
}

void AFortCharacterVehicle_Ostrich::MulticastDriverInput_Implementation(bool bIsPrimaryFire)
{
}

void AFortCharacterVehicle_Ostrich::OnDashFinished()
{
}

void AFortCharacterVehicle_Ostrich::OnDashStart()
{
}

void AFortCharacterVehicle_Ostrich::OnKickFinished()
{
}

void AFortCharacterVehicle_Ostrich::OnKickStomp()
{
}

void AFortCharacterVehicle_Ostrich::OnPickupCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AFortCharacterVehicle_Ostrich::OnRep_ChargeJump()
{
}

void AFortCharacterVehicle_Ostrich::OnRep_Detonating()
{
}

void AFortCharacterVehicle_Ostrich::OnRep_IsDashing()
{
}

void AFortCharacterVehicle_Ostrich::OnRep_Kick()
{
}

void AFortCharacterVehicle_Ostrich::OnStartShotgunReload()
{
}

void AFortCharacterVehicle_Ostrich::ServerNotifyDriverInput_Implementation(bool bIsPrimaryFire)
{
}
bool AFortCharacterVehicle_Ostrich::ServerNotifyDriverInput_Validate(bool bIsPrimaryFire)
{
	return true;
}

void AFortCharacterVehicle_Ostrich::ServerSetJumpCharging_Implementation(bool bNewCharging)
{
}
bool AFortCharacterVehicle_Ostrich::ServerSetJumpCharging_Validate(bool bNewCharging)
{
	return true;
}

void AFortCharacterVehicle_Ostrich::SetLinearAudioComp(UFortVehicleAudioVoice* LinearAudio)
{
}

void AFortCharacterVehicle_Ostrich::SetRotationalAudioComp(UFortVehicleAudioVoice* RotAudio)
{
}

void AFortCharacterVehicle_Ostrich::SetShieldActor(AActor* InShieldActor)
{
}

void AFortCharacterVehicle_Ostrich::SetTargetingLaserAudioComp(UAudioComponent* TargetingLaserAudio)
{
}

void AFortCharacterVehicle_Ostrich::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, ShieldActor);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bDriverStompImmersionBlocked);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bDriverDashImmersionBlocked);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bDriverJumpImmersionBlocked);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bGunnerMissilesImmersionBlocked);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bGunnerShotgunImmersionBlocked);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bChargingJump);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bChargingRockets);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bAutomaticallyFiringShotgun);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, DetonationState);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bDashing);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, bKickRep);
	DOREPLIFETIME(AFortCharacterVehicle_Ostrich, CachedWeaponState);
}
