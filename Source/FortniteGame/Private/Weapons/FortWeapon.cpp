// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeapon.h"
#include "Net/UnrealNetwork.h"

bool AFortWeapon::AllowReloadWhenFull() const
{
	return false;
}

void AFortWeapon::AttemptApplyOverrideWrapToActor(AActor* Actor) const
{
}

float AFortWeapon::CalcConsumeSpeedMultiplierSafe() const
{
	return float();
}

void AFortWeapon::CancelActiveAbility()
{
}

bool AFortWeapon::CanFire(bool bPrimaryFire) const
{
	return false;
}

void AFortWeapon::CheckPendingFire()
{
}

void AFortWeapon::ClearOverrideFireModeData()
{
}

void AFortWeapon::ClientGivenTo_Implementation(APawn* P)
{
}

void AFortWeapon::ClientHandleReloadFromAbility_Implementation()
{
}

void AFortWeapon::ClientReportShotFlags_Implementation(uint32 ShotFlags, int32 ShotIndex)
{
}

FColor AFortWeapon::DetermineReticleColor()
{
	return FColor();
}

bool AFortWeapon::DoesHaveOverrideWrap() const
{
	return false;
}

void AFortWeapon::EndCharge()
{
}

void AFortWeapon::GameplayCue_Impact(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void AFortWeapon::GameplayCue_Weapons_Activation(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

float AFortWeapon::GetAccumulatedChargeTime() const
{
	return float();
}

TArray<UFortAlterationItemDefinition*> AFortWeapon::GetAlterations() const
{
	return TArray<UFortAlterationItemDefinition*>();
}

int32 AFortWeapon::GetAmmoCostPerFire(float ChargePercentage) const
{
	return int32();
}

FItemVariantHandle AFortWeapon::GetAmmoVariantHandle_Implementation(const UFortWorldItemDefinition* AmmoItemDefinition) const
{
	return FItemVariantHandle();
}

UAudioParameterComponent* AFortWeapon::GetAudioParameterComponent() const
{
	return nullptr;
}

int32 AFortWeapon::GetBulletsPerClip() const
{
	return int32();
}

USoundBase* AFortWeapon::GetChargedWeaponFireSound_Implementation(EFortWeaponSoundState::Type Channel, const bool bSecondaryFire) const
{
	return nullptr;
}

float AFortWeapon::GetChargePercent() const
{
	return float();
}

float AFortWeapon::GetChargeTime() const
{
	return float();
}

float AFortWeapon::GetChargeToAutoDischarge() const
{
	return float();
}

float AFortWeapon::GetChargeToMinPercent() const
{
	return float();
}

EFortWeaponCoreAnimation::Type AFortWeapon::GetCoreAnimation() const
{
	return EFortWeaponCoreAnimation::Type();
}

float AFortWeapon::GetCurrentMaxChargePercent() const
{
	return float();
}

FVector AFortWeapon::GetDamageStartLocation(FVector& AimDir, int32 PatternIndex) const
{
	return FVector();
}

UAnimMontage* AFortWeapon::GetEquipAnimation() const
{
	return nullptr;
}

float AFortWeapon::GetFiringRate() const
{
	return float();
}

const TArray<FWeaponHudData>& AFortWeapon::GetHudKeyActionData() const
{
	static TArray<FWeaponHudData> Dummy;
	return Dummy;
}

FGuid AFortWeapon::GetInventoryGUID() const
{
	return FGuid();
}

const UFortItem* AFortWeapon::GetInventoryItem() const
{
	return nullptr;
}

bool AFortWeapon::GetIsChargingWeapon() const
{
	return false;
}

bool AFortWeapon::GetIsReloadingWeapon() const
{
	return false;
}

bool AFortWeapon::GetIsTargeting() const
{
	return false;
}

bool AFortWeapon::GetItemTemplateObjects(TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled) const
{
	return false;
}

float AFortWeapon::GetLastFireTime() const
{
	return float();
}

int32 AFortWeapon::GetLocalMagazineAmmoCount() const
{
	return int32();
}

int32 AFortWeapon::GetLocalRemainingAmmo() const
{
	return int32();
}

int32 AFortWeapon::GetMagazineAmmoCount() const
{
	return int32();
}

float AFortWeapon::GetMeleeAttackPlayRate()
{
	return float();
}

FVector AFortWeapon::GetMuzzleLocation_Implementation(int32 PatternIndex) const
{
	return FVector();
}

FName AFortWeapon::GetMuzzleSocketName(int32 PatternIndex) const
{
	return FName();
}

FTransform AFortWeapon::GetMuzzleSocketTransform(int32 PatternIndex) const
{
	return FTransform();
}

bool AFortWeapon::GetPickupInstigatorData(int32& InstigatorHandle, FPickupInstigatorData& InstigatorData) const
{
	return false;
}

void AFortWeapon::GetPlayerActiveGrantedGameplayTags(FGameplayTagContainer& GameplayTags) const
{
}

FFortPlayerAnimAssets AFortWeapon::GetPlayerAnimAssets() const
{
	return FFortPlayerAnimAssets();
}

UProxyTable* AFortWeapon::GetPlayerAnimProxyTable() const
{
	return nullptr;
}

FFortProceduralLayeringWeaponData AFortWeapon::GetProceduralLayeringData() const
{
	return FFortProceduralLayeringWeaponData();
}

float AFortWeapon::GetProjectilePitchOffset() const
{
	return float();
}

float AFortWeapon::GetProjectileSpeed(float ChargePercent) const
{
	return float();
}

float AFortWeapon::GetRange() const
{
	return float();
}

UAnimMontage* AFortWeapon::GetReloadAnimation() const
{
	return nullptr;
}

float AFortWeapon::GetReloadProgress() const
{
	return float();
}

float AFortWeapon::GetReloadTime() const
{
	return float();
}

int32 AFortWeapon::GetRemainingAmmo() const
{
	return int32();
}

FColor AFortWeapon::GetReticleColor() const
{
	return FColor();
}

bool AFortWeapon::GetReticleColorOverride_Implementation(FColor& OutColor, const TArray<FHitResult>& HitResults) const
{
	return false;
}

UFortSoundLibraryComponent* AFortWeapon::GetSoundLibraryComponent(FGameplayTag InComponentTag) const
{
	return nullptr;
}

bool AFortWeapon::GetSupportsAutoFireAtReticleTargetMode() const
{
	return false;
}

float AFortWeapon::GetSurfaceRatioMultiplier(EPhysicalSurface HitSurface, const AActor* HitInstigator, const AActor* HitTarget) const
{
	return float();
}

float AFortWeapon::GetTimeToNextFire() const
{
	return float();
}

int32 AFortWeapon::GetTraceThroughBuildingsLimit() const
{
	return int32();
}

int32 AFortWeapon::GetTraceThroughLandscapeLimit() const
{
	return int32();
}

bool AFortWeapon::GetTraceThroughPawns() const
{
	return false;
}

int32 AFortWeapon::GetTraceThroughPawnsLimit() const
{
	return int32();
}

FGuid AFortWeapon::GetTrackerGuid() const
{
	return FGuid();
}

UFortWeaponAdditiveAnimSet* AFortWeapon::GetWeaponAdditiveAnimSet() const
{
	return nullptr;
}

EFortWeaponChargeStateForFireFX AFortWeapon::GetWeaponChargeStateForFireFX() const
{
	return EFortWeaponChargeStateForFireFX();
}

UFortWeaponItemDefinition* AFortWeapon::GetWeaponData() const
{
	return nullptr;
}

UFortWorldItemDefinition* AFortWeapon::GetWeaponDataAmmoWorldItemDefinition() const
{
	return nullptr;
}

void AFortWeapon::GetWeaponDataGameplayTags(FGameplayTagContainer& GameplayTags) const
{
}

EFortItemType AFortWeapon::GetWeaponDataItemType() const
{
	return EFortItemType();
}

void AFortWeapon::GetWeaponDataPlayerGrantedGameplayTags(FGameplayTagContainer& GameplayTags) const
{
}

EFortRarity AFortWeapon::GetWeaponDataRarity() const
{
	return EFortRarity();
}

TSoftObjectPtr<UTexture2D> AFortWeapon::GetWeaponDataSmallPreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

FSlateBrush AFortWeapon::GetWeaponDataSmallPreviewImageBrush() const
{
	return FSlateBrush();
}

EFortWeaponTriggerType::Type AFortWeapon::GetWeaponDataTriggerType() const
{
	return EFortWeaponTriggerType::Type();
}

FDataTableRowHandle AFortWeapon::GetWeaponDataWeaponStatHandle() const
{
	return FDataTableRowHandle();
}

UAnimMontage* AFortWeapon::GetWeaponEquipMontage() const
{
	return nullptr;
}

USkeletalMeshComponentBudgeted* AFortWeapon::GetWeaponMesh() const
{
	return nullptr;
}

void AFortWeapon::GetWeaponMeshes(TArray<USkeletalMeshComponentBudgeted*>& WeaponMeshes) const
{
}

const TArray<FFortWeaponModSlot>& AFortWeapon::GetWeaponModSlots() const
{
	static TArray<FFortWeaponModSlot> Dummy;
	return Dummy;
}

UFortWeaponAnimSet* AFortWeapon::GetWeaponPawnAnimSet() const
{
	return nullptr;
}

float AFortWeapon::GetWeaponRateOfFireModifier()
{
	return float();
}

UAnimMontage* AFortWeapon::GetWeaponReloadMontage() const
{
	return nullptr;
}

void AFortWeapon::HandleBlueprintProbablyCosmeticStomp()
{
}

bool AFortWeapon::HasAnyVisibleHudKeyActionData() const
{
	return false;
}

bool AFortWeapon::HasInfiniteAmmo() const
{
	return false;
}

bool AFortWeapon::InventoryOwnerHasInfiniteAmmo() const
{
	return false;
}

bool AFortWeapon::IsBeingEquipped() const
{
	return false;
}

bool AFortWeapon::IsCosmeticLimited() const
{
	return false;
}

bool AFortWeapon::IsEquipped() const
{
	return false;
}

bool AFortWeapon::IsFiring() const
{
	return false;
}

bool AFortWeapon::IsGauntlet() const
{
	return false;
}

bool AFortWeapon::IsProjectileWeapon() const
{
	return false;
}

bool AFortWeapon::IsQuartzGunfireEnabled() const
{
	return false;
}

bool AFortWeapon::IsReloading() const
{
	return false;
}

bool AFortWeapon::IsSuppressed() const
{
	return false;
}

bool AFortWeapon::IsTargeting() const
{
	return false;
}

void AFortWeapon::K2_ConsumeAmmo(const int32 Quantity, const bool bCheckInfiniteAmmo)
{
}

void AFortWeapon::ModAmmo(int32 AmountToUse)
{
}

void AFortWeapon::OnPawnMontageBlendingOut(UAnimMontage* PawnMontage, bool bInterrupted)
{
}

void AFortWeapon::OnPawnMontageStarted(UAnimMontage* PawnMontage)
{
}

void AFortWeapon::OnPlayImpactFX_Implementation(const FHitResult& HitResult, EPhysicalSurface ImpactPhysicalSurface, UFXSystemComponent* SpawnedPSC)
{
}

void AFortWeapon::OnRep_AmmoCount(int32 OldAmmoCount)
{
}

void AFortWeapon::OnRep_ChargeStatusPack()
{
}

void AFortWeapon::OnRep_EquippedWeaponDestroyWrapper()
{
}

void AFortWeapon::OnRep_IsEquippingWeapon()
{
}

void AFortWeapon::OnRep_LastFireTimeVerified()
{
}

void AFortWeapon::OnRep_PhantomReserveAmmo()
{
}

void AFortWeapon::OnRep_PrimaryAbilitySpecHandle()
{
}

void AFortWeapon::OnRep_ReplicatedAppliedAlterations()
{
}

void AFortWeapon::OnRep_ReplicatedCosmeticOverrideWeaponData()
{
}

void AFortWeapon::OnRep_ReplicatedWeaponData()
{
}

void AFortWeapon::OnRep_ReplicatedWeaponModSlots(const TArray<FFortWeaponModSlot>& PreviousModSlots)
{
}

void AFortWeapon::OnWeaponMontageBlendingOut(UAnimMontage* WeaponMontage, bool bInterrupted)
{
}

void AFortWeapon::OnWeaponMontageStarted(UAnimMontage* WeaponMontage)
{
}

void AFortWeapon::OnWeaponVisibilityChanged_Implementation(bool bVisible, bool bSetForLocalControllerOnly)
{
}

void AFortWeapon::PlayForceFeedback(bool bSecondaryFire, bool bPersistentFire, bool bImpact)
{
}

void AFortWeapon::PlayNativeImpactFX(const FHitResult& HitResult, const FGameplayCueParameters& GameplayCueParameters)
{
}

void AFortWeapon::PlayReloadFX(EFortReloadFXState::Type ReloadStage)
{
}

void AFortWeapon::PlayWeaponFireFX(bool bSecondaryFire)
{
}

void AFortWeapon::Reload()
{
}

void AFortWeapon::ResetPlayerAnimAssetOverride()
{
}

void AFortWeapon::ResetTempWeaponMaterialOverride()
{
}

void AFortWeapon::ResetWeaponCoreAnimOverride()
{
}

void AFortWeapon::RestoreOriginalMaterials()
{
}

void AFortWeapon::ServerResetShotReport_Implementation()
{
}

void AFortWeapon::ServerSetChargeState_Implementation(uint8 NewState)
{
}

void AFortWeapon::SetAllowReloadWhenFull(const bool bNewAllowReloadWhenFull)
{
}

void AFortWeapon::SetBase3PCamera(const TSubclassOf<UFortCameraMode>& NewBaseCam)
{
}

void AFortWeapon::SetChargeTime(float InChargeTime)
{
}

void AFortWeapon::SetFeedbackLinesDimFlag(bool bIsDimmed)
{
}

void AFortWeapon::SetFireSoundPitchMultiplier(const float NewPitch)
{
}

bool AFortWeapon::SetHiddenInGameControllerOnly(USceneComponent* SceneComp, const bool NewHidden, const bool bPropagateToChildren)
{
	return false;
}

bool AFortWeapon::SetHiddenInGameOtherLocalControllersOnly(USceneComponent* SceneComp, const bool NewHidden, const bool bPropagateToChildren)
{
	return false;
}

bool AFortWeapon::SetHudKeyActionDescription(int32 Index, FText InActionDescription)
{
	return false;
}

bool AFortWeapon::SetHudKeyActionDescriptionByID(const FString& KeyActionId, FText InActionDescription)
{
	return false;
}

void AFortWeapon::SetHudKeyActionsVisibility(const TArray<FWeaponHudKeyActionVisibility>& IndexVisibilityArray)
{
}

bool AFortWeapon::SetHudKeyActionVisibility(int32 Index, bool bVisible)
{
	return false;
}

bool AFortWeapon::SetHudKeyActionVisibilityByID(const FString& KeyActionId, bool bVisible)
{
	return false;
}

void AFortWeapon::SetIsReloadingWeapon(bool bReloading)
{
}

void AFortWeapon::SetNativeChargeUpEnabled(const bool bEnabled)
{
}

void AFortWeapon::SetOverrideFireModeData(const TSoftObjectPtr<UFortWeaponFireModeData>& OverrideFireModeData)
{
}

void AFortWeapon::SetPlayerAnimAssetOverride(FFortPlayerAnimAssets InPlayerAnimAssetsOverride, bool bResetOnUnequip)
{
}

void AFortWeapon::SetShouldDrawNativeReticle(bool bInShouldDrawReticle)
{
}

void AFortWeapon::SetTargeting3PCamera(const TSubclassOf<UFortCameraMode>& NewTargetingCam)
{
}

void AFortWeapon::SetTargetingReload3PCamera(const TSubclassOf<UFortCameraMode>& NewTargetingReloadCam)
{
}

void AFortWeapon::SetTraceThroughBuildingsLimit(int32 NewTraceThroughBuildingsLimit)
{
}

void AFortWeapon::SetTraceThroughLandscapeLimit(int32 NewTraceThroughTerrainLimit)
{
}

void AFortWeapon::SetTraceThroughPawns(bool bNewTraceThroughPawns)
{
}

void AFortWeapon::SetTraceThroughPawnsLimit(int32 NewTraceThroughPawnsLimit)
{
}

void AFortWeapon::SetTrajectoryVisibility(const bool bNewVisible)
{
}

void AFortWeapon::SetTrajectoryVisibilityControllerOnly(AFortPlayerController* FortPlayerController, const bool bNewVisible)
{
}

void AFortWeapon::SetWeaponCoreAnimOverride(EFortWeaponCoreAnimation::Type InWeaponCoreAnimationOverride)
{
}

void AFortWeapon::SetWeaponData(UFortWeaponItemDefinition* InWeaponData)
{
}

void AFortWeapon::SetWeaponPawnAnimsetOverride(UFortWeaponAnimSet* WeaponPawnAnimsetOverride)
{
}

void AFortWeapon::SetWeaponVisibility(const bool bDesiredVisibility, const bool bForceUpdate)
{
}

void AFortWeapon::SetWeaponVisibilityControllerOnly(const bool bDesiredVisibility, const bool bForceUpdate)
{
}

bool AFortWeapon::ShouldCustomTriggerPerformPendingFire_Implementation() const
{
	return false;
}

void AFortWeapon::ShowWeaponFireAudioVisual()
{
}

void AFortWeapon::StartCharge()
{
}

void AFortWeapon::StopForceFeedback()
{
}

void AFortWeapon::StopWeaponFireFX()
{
}

bool AFortWeapon::TryReloadAmmoFromAbility()
{
	return false;
}

void AFortWeapon::TryToCustomFire()
{
}

void AFortWeapon::UpdateDamageStartLocation()
{
}

void AFortWeapon::UseWeaponDurability(float DurabilityScale)
{
}

bool AFortWeapon::WeaponDataHasAnyMatchingGameplayTags(const FGameplayTagContainer TagContainer) const
{
	return false;
}

bool AFortWeapon::WeaponDataHasMatchingGameplayTag(const FGameplayTag TagToCheck) const
{
	return false;
}

bool AFortWeapon::WeaponDataIsValid() const
{
	return false;
}

void AFortWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeapon, bIsEquippingWeapon);
	DOREPLIFETIME(AFortWeapon, bIsReloadingWeapon);
	DOREPLIFETIME(AFortWeapon, bIsChargingWeapon);
	DOREPLIFETIME(AFortWeapon, bDisableEquipAnimation);
	DOREPLIFETIME(AFortWeapon, WeaponData);
	DOREPLIFETIME(AFortWeapon, CosmeticOverrideWeaponData);
	DOREPLIFETIME(AFortWeapon, EquippedWeaponDestroyWrapperRepCounter);
	DOREPLIFETIME(AFortWeapon, LastFireTimeVerified);
	DOREPLIFETIME(AFortWeapon, ItemEntryGuid);
	DOREPLIFETIME(AFortWeapon, TrackerGuid);
	DOREPLIFETIME(AFortWeapon, WeaponLevel);
	DOREPLIFETIME(AFortWeapon, AmmoCount);
	DOREPLIFETIME(AFortWeapon, PhantomReserveAmmo);
	DOREPLIFETIME(AFortWeapon, ChargeStatusPack);
	DOREPLIFETIME(AFortWeapon, ActiveAbility);
	DOREPLIFETIME(AFortWeapon, PrimaryAbilitySpecHandle);
	DOREPLIFETIME(AFortWeapon, SecondaryAbilitySpecHandle);
	DOREPLIFETIME(AFortWeapon, ReloadAbilitySpecHandle);
	DOREPLIFETIME(AFortWeapon, ImpactAbilitySpecHandle);
	DOREPLIFETIME(AFortWeapon, ReticleTraceOverrideSpecHandle);
	DOREPLIFETIME(AFortWeapon, AppliedAlterations);
	DOREPLIFETIME(AFortWeapon, WeaponModSlots);
}

void AFortWeapon::GetActorSoundParams_Implementation(TArray<FAudioParameter>& Params) const
{
}
