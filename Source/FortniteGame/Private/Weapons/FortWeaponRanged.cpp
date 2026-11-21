// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRanged.h"
#include "Net/UnrealNetwork.h"

void AFortWeaponRanged::ActivateMuzzleFlashFXNative(const bool bPersistantFire, const bool bMuzzleUsesNiagara, const TSoftObjectPtr<UNiagaraSystem>& MuzzleNiagaraAsset, const TArray<UParticleSystemComponent*>& LegacyMuzzleFXComponents, const float MuzzleChanceOfLargeFlash, const float MuzzleFlashLargeMinScale, const float MuzzleFlashLargeMaxScale, const float MuzzleFlashSmallMinScale, const float MuzzleFlashSmallMaxScale)
{
}

void AFortWeaponRanged::ActivateShellsFXNative(UNiagaraSystem* ShellBurstFX, UNiagaraSystem* ShellLoopingFX, const FName ShellSocketName, const FName RotationRateName, const FVector& RotationRate, const FName VelocityName, const FVector& Velocity, const FName GravityName, const FVector& Gravity, const FName SizeName, const FVector& Size, const FName ParentVelocityName, const FVector& ParentVelocity, const FName RadiusName, const float Radius, const FName HeightName, const float Height, const FName ColorName, const FLinearColor& ShellColor, const FName ShellTypeName, const int32 ShellTypeInt, const float CullDistance, const bool bUseShellsOnReload, const FName SpawnProbabilityName, const float SpawnRateScale)
{
}

bool AFortWeaponRanged::BP_AllowRaiseWeaponForDeferredFireInput_Implementation() const
{
	return false;
}

void AFortWeaponRanged::ClearHomingTarget()
{
}

void AFortWeaponRanged::ClientFixOverheatState_Implementation(EFortWeaponOverheatState NewOverheatState)
{
}

void AFortWeaponRanged::ClientFixupOverheatValue_Implementation(const float InOverheatValue)
{
}

void AFortWeaponRanged::DeactivateBeamFX()
{
}

void AFortWeaponRanged::DeactivateMuzzleFlashFXNative(const TArray<UParticleSystemComponent*>& LegacyMuzzleFXComponents)
{
}

void AFortWeaponRanged::DeactivateShellsFXNative(const FName SpawnProbabilityName)
{
}

bool AFortWeaponRanged::DoesWeaponOverheat() const
{
	return false;
}

void AFortWeaponRanged::EnableAltCenterReticle(bool bNewEnabled)
{
}

void AFortWeaponRanged::EnableAltOuterReticle(bool bNewEnabled)
{
}

void AFortWeaponRanged::EnableCornersReticle(bool bNewEnabled)
{
}

float AFortWeaponRanged::GetADSTransitionInTime() const
{
	return float();
}

float AFortWeaponRanged::GetADSTransitionOutTime() const
{
	return float();
}

UNiagaraComponent* AFortWeaponRanged::GetBeamNiagaraComponent() const
{
	return nullptr;
}

UNiagaraSystem* AFortWeaponRanged::GetBeamNiagaraSystem() const
{
	return nullptr;
}

UParticleSystem* AFortWeaponRanged::GetBeamParticleSystem() const
{
	return nullptr;
}

UParticleSystemComponent* AFortWeaponRanged::GetBeamPSC() const
{
	return nullptr;
}

float AFortWeaponRanged::GetCalculatedReticleSpread() const
{
	return float();
}

float AFortWeaponRanged::GetCurrentOverheatValue() const
{
	return float();
}

float AFortWeaponRanged::GetCurrentReticleSpreadMultiplier() const
{
	return float();
}

UAnimMontage* AFortWeaponRanged::GetFireAnimation() const
{
	return nullptr;
}

UAnimMontage* AFortWeaponRanged::GetFireDownsightsAnimation() const
{
	return nullptr;
}

float AFortWeaponRanged::GetMaxAdditionalPatternSpreadDegrees() const
{
	return float();
}

float AFortWeaponRanged::GetOverheatingMaxValue() const
{
	return float();
}

EFortWeaponOverheatState AFortWeaponRanged::GetOverheatState() const
{
	return EFortWeaponOverheatState();
}

const TArray<FWeightedBlendable>& AFortWeaponRanged::GetScopePostProcessMaterial() const
{
	static TArray<FWeightedBlendable> Dummy;
	return Dummy;
}

int32 AFortWeaponRanged::GetShellReloadCounter() const
{
	return int32();
}

TSubclassOf<AFortTracerBase> AFortWeaponRanged::GetTracerTemplate() const
{
	return TSubclassOf<AFortTracerBase>();
}

void AFortWeaponRanged::GetUniqueMuzzleSocketNames(TArray<FName>& Names) const
{
}

bool AFortWeaponRanged::GetUseBeamParticles() const
{
	return false;
}

UAnimMontage* AFortWeaponRanged::GetWeaponFireDownsightsMontage() const
{
	return nullptr;
}

UAnimMontage* AFortWeaponRanged::GetWeaponFireMontage() const
{
	return nullptr;
}

bool AFortWeaponRanged::HasPostProcessMaterialFromOptic() const
{
	return false;
}

void AFortWeaponRanged::InitializeBeamFX(UFXSystemComponent* InBeamPSC)
{
}

void AFortWeaponRanged::InitUpdateOverheatingState()
{
}

bool AFortWeaponRanged::IsCachedIsProjectileWeapon_Implementation() const
{
	return false;
}

bool AFortWeaponRanged::IsOverheated() const
{
	return false;
}

bool AFortWeaponRanged::IsUsingFirstPersonCamera() const
{
	return false;
}

bool AFortWeaponRanged::IsUsingScope() const
{
	return false;
}

bool AFortWeaponRanged::IsUsingScopeOrFirstPersonCamera() const
{
	return false;
}

void AFortWeaponRanged::MulticastLWProjectile_EndActiveAbility_Implementation(const float FiringTimestamp)
{
}

void AFortWeaponRanged::MulticastProjectileRequestReliable_Implementation(const FFortLightweightProjectileRequest& ProjectileRequest)
{
}

void AFortWeaponRanged::MulticastProjectileRequestUnreliable_Implementation(const FFortLightweightProjectileRequest& ProjectileRequest)
{
}

void AFortWeaponRanged::MulticastStopProjectileRequestUnreliable_Implementation(AActor* Requester)
{
}

void AFortWeaponRanged::NetMulti_SimulateFireFX_Implementation()
{
}

void AFortWeaponRanged::OnRep_OverheatState(EFortWeaponOverheatState PreviousOverheatState)
{
}

void AFortWeaponRanged::OnRep_ReplayActivationCue()
{
}

void AFortWeaponRanged::OnRep_ReplayImpactCue()
{
}

void AFortWeaponRanged::ReleaseShellsFXNative()
{
}

void AFortWeaponRanged::ServerLWProjectile_EndActiveAbility_Implementation(const float FiringTimestamp)
{
}

void AFortWeaponRanged::ServerLWProjectile_SetDamageStartAndDirection_Implementation(const FVector& InDamageStart, const FVector& InDamageDirection)
{
}

void AFortWeaponRanged::ServerNotifyPawnHit_Implementation(FHitResult Hit, const FVector& ProjectileOriginPosition, const TArray<uint8>& Context)
{
}

void AFortWeaponRanged::ServerSendRotationDebugInfo_Implementation(const FRotationDebugInfo& DebugInfo)
{
}

void AFortWeaponRanged::ServerSetMuzzleTraceNearWall_Implementation(bool bIsNearWall)
{
}

void AFortWeaponRanged::ServerStopProjectileRequest_Implementation()
{
}
bool AFortWeaponRanged::ServerStopProjectileRequest_Validate()
{
	return true;
}

UNiagaraSystem* AFortWeaponRanged::SetBeamNiagaraSystem(UNiagaraSystem* InputBeamNiagaraSystem)
{
	return nullptr;
}

UParticleSystem* AFortWeaponRanged::SetBeamParticleSystem(UParticleSystem* InputBeamParticleSystem)
{
	return nullptr;
}

void AFortWeaponRanged::SetDecalColorEnd(FLinearColor InputDecalColorEnd)
{
}

void AFortWeaponRanged::SetDecalColorStart(FLinearColor InputDecalColorStart)
{
}

void AFortWeaponRanged::SetFirstPersonTargeting(const bool bNewUseFirstPersonTargeting)
{
}

void AFortWeaponRanged::SetHomingTarget(AFortPawn* PlayerPawn)
{
}

void AFortWeaponRanged::SetShellReloadCounter(int32 InputShellReloadCounter)
{
}

void AFortWeaponRanged::SetUseBeamParticles(bool bNewUseBeamParticles)
{
}

void AFortWeaponRanged::SetUseImpactDecals(bool bNewUseImpactDecals)
{
}

void AFortWeaponRanged::SetUseOverrideBaseSpread(bool bUseOverride)
{
}

void AFortWeaponRanged::SetUseOverrideSpreadDownsightsMultiplier(bool bUseOverride)
{
}

void AFortWeaponRanged::SetUseShellsParticles(bool bNewUseShellsParticles)
{
}

void AFortWeaponRanged::SetUseTracers(bool bNewUseTracers)
{
}

bool AFortWeaponRanged::ShouldDisplayAmmoCounter() const
{
	return false;
}

bool AFortWeaponRanged::ShouldDisplayAmmoCounterDuringSecondaryFire() const
{
	return false;
}

bool AFortWeaponRanged::ShouldDisplayReticleAmmoCounter() const
{
	return false;
}

bool AFortWeaponRanged::ShouldDisplayReticleOverheatIndicator()
{
	return false;
}

bool AFortWeaponRanged::ShouldHideReticleAmmoCounterWhileTargeting() const
{
	return false;
}

bool AFortWeaponRanged::ShouldPlayPersistentFireFX() const
{
	return false;
}

bool AFortWeaponRanged::ShouldPlayReloadFX() const
{
	return false;
}

bool AFortWeaponRanged::ShouldPlayShellFX() const
{
	return false;
}

bool AFortWeaponRanged::ShouldSpawnBulletShellFX()
{
	return false;
}

void AFortWeaponRanged::TempHack_PlayOverheatedAnimation()
{
}

bool AFortWeaponRanged::UseFirstPersonTargeting() const
{
	return false;
}

bool AFortWeaponRanged::UseScopeTargeting() const
{
	return false;
}

void AFortWeaponRanged::VehicleSeatScopeFxHide(int32 SeatIndex)
{
}

void AFortWeaponRanged::VehicleSeatScopeFxShow()
{
}

void AFortWeaponRanged::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponRanged, ReplayActivationCue);
	DOREPLIFETIME(AFortWeaponRanged, ReplayImpactCue);
	DOREPLIFETIME(AFortWeaponRanged, bUseOverrideBaseSpread);
	DOREPLIFETIME(AFortWeaponRanged, bUseOverrideSpreadDownsightsMultiplier);
	DOREPLIFETIME(AFortWeaponRanged, bIsMuzzleTraceNearWall);
	DOREPLIFETIME(AFortWeaponRanged, OverheatState);
	DOREPLIFETIME(AFortWeaponRanged, TimeOverheatedBegan);
	DOREPLIFETIME(AFortWeaponRanged, LWProjectile_DamageStart);
	DOREPLIFETIME(AFortWeaponRanged, LWProjectile_DamageDirection);
}
