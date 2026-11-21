// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Audio/ActorSoundParameterInterface.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/DataTable.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Abilities/FortGameplayAbility.h"
#include "Animation/FortPlayerAnimAssets.h"
#include "Cosmetics/Variants/FortCosmeticVariantCache.h"
#include "Effects/FortNiagaraDataChannels.h"
#include "FortAnalyticsInterface.h"
#include "FortCombatTypes.h"
#include "FortCustomPartTypeEnum.h"
#include "FortDamageSourceInterface.h"
#include "FortEffectDistanceQuality.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortItemVariantHandle.h"
#include "FortPickupInstigatorInterface.h"
#include "FortSoundIndicatorInterface.h"
#include "FortTeamActorInterface.h"
#include "FortWeaponEnums.h"
#include "FortWeaponSoundStateEnum.h"
#include "STW/Items/FortCosmeticModification.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "Weapons/Data/FortWeaponModSlot.h"
#include "Weapons/FortEquippedWeaponModSlot.h"
#include "Weapons/FortProceduralLayeringWeaponData.h"
#include "Weapons/FortWeaponDelegates.h"
#include "FortWeapon.generated.h"

class AActor;
class ACustomItemWrapModifier;
class AFortFXManager;
class AFortPlayerController;
class AFortProjectileTrajectory;
class AFortWeapon;
class APawn;
class UAnimInstance;
class UAnimMontage;
class UAnimSequence;
class UAthenaItemWrapDefinition;
class UAudioComponent;
class UAudioParameterComponent;
class UFXSystemComponent;
class UForceFeedbackEffect;
class UFortAlterationItemDefinition;
class UFortCameraMode;
class UFortCreativeItemTemplate;
class UFortGameplayAbility;
class UFortGenericDataStoreManagerComponent;
class UFortItem;
class UFortQuartzGunfireComponent;
class UFortSignificanceManager;
class UFortSoundIndicatorComponent;
class UFortSoundLibraryComponent;
class UFortWeaponAdditiveAnimSet;
class UFortWeaponAnimSet;
class UFortWeaponFireModeData;
class UFortWeaponFirstPersonData;
class UFortWeaponItemDefinition;
class UFortWeaponModDebugComponent;
class UFortWeaponModItemDefinition;
class UFortWeaponModRuntimeData;
class UFortWeaponOpticDefinition;
class UFortWorldItemDefinition;
class ULegacyCameraShake;
class UMaterialInterface;
class UNiagaraSystem;
class UParticleSystem;
class UProxyTable;
class USceneComponent;
class USkeletalMeshComponentBudgeted;
class USoundBase;
class UTexture2D;
class UWeaponHitNotifyAudioBank;
class UWeaponImpactData;
enum class EFortAbilityTargetingSource : uint8;
enum class EFortItemType : uint8;
enum class EFortRarity : uint8;
enum class EFortWeaponChargeStateForFireFX : uint8;
enum class EFortWeaponReloadType : uint8;

UENUM()
namespace EFortReloadMontageSection
{
	enum Type
	{
		Intro = 0,
		Loop = 1,
		Outro = 2,
	};
}

UENUM()
enum class EFortWeaponAbilityRemovalPolicy : uint8
{
	/** If specified, removal behavior will fall back to the default behavior exhibited by respective game mode */
	GameDefault = 0,
	/** If specified, abilities will be removed for the associated removal reason */
	Remove = 1,
	/** If specified, abilities will persist for the associated removal reason */
	Persist = 2,
};

UENUM(BlueprintType)
enum class EFortWeaponAbilityRemovalReason : uint8
{
	/** Weapon is being removed from its owner's inventory */
	RemovedFromInventory = 0,
	/** The weapon actor has had EndPlay called on it */
	EndPlay = 1,
	/** The weapon has been unequipped */
	Unequipped = 2,
	/** Invalid option, used for array size/index */
	INVALID_MAX = 3,
};

UENUM(BlueprintType)
enum class EFortWeaponChargeStateForFireFX : uint8
{
	Partial = 0,
	// Charging but not full yet.

	Full = 1,
	// Full charge.

	Over = 2,
	// Passed full charge and we're now into overcharge.

	Max_None = 3 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EFortWeaponReduceMeshWorkSetting : uint8
{
	DisableTick = 0,
	// Default

	DontReduceWork = 1,
	// If set, this weapon should tick as if it were a primary animation asset. Used as a per-weapon override to ensure proper weapon/character IK (ExplosiveBow, etc.)

	HandledInAnimInstance = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FiveParams(FOnBeamFired, AFortWeapon*, Weapon, bool, bUsePersistentBeam, UFXSystemComponent*, PSC, const FVector&, BeamOrigin, const FVector&, HitLocation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConsumeAmmo, int32, Quantity);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnGetWeaponAimRotOverride, const AFortWeapon*, Weapon, const EFortAbilityTargetingSource, TargetingSource, FRotator&, OutOverrideAimRot, bool&, bOutExecutionResult);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocalAmmoChanged, int32, LocalCount, int32, LocalRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalReloadCancelled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocalReloadStarted, float, ReloadTime, EFortWeaponReloadType, ReloadType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalTargetingChanged, bool, bIsTargeting);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayImpactFX, AFortWeapon*, Weapon, const FHitResult&, HitResult, UFXSystemComponent*, FXSystemComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRateOfFireChanged, float, NewRateOfFire);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReticleColorChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSecondaryAbilityToggled, bool, bSecondaryAbilityToggled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetingChanged, bool, bIsTargeting);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponVisibilityChanged, bool, bVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeaponEventDelegate, AFortWeapon*, Weapon);

USTRUCT(BlueprintType)
struct FMaterialInterfaceArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MaterialInterfaceArray")
	TArray<TObjectPtr<UMaterialInterface>> Materials;

};

USTRUCT(BlueprintType)
struct FWeaponHudData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FName KeyActionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FName GamepadActionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FText ActionDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	bool bVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	bool bIsDimmed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	bool bIsAxisMapping;

	UPROPERTY(EditAnywhere, Category="Hud Data", meta=(EditCondition="bIsAxisMapping", EditConditionHides))
	float AxisScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FGameplayTagContainer DisabledTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FString KeyActionId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hud Data")
	FGameplayTag WatchTag;

};

USTRUCT(BlueprintType)
struct FWeaponHudKeyActionVisibility
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Hud Data")
	int32 Index;

	UPROPERTY(BlueprintReadWrite, Category="Hud Data")
	bool bVisibility;

};

USTRUCT()
struct FWeaponImpactArraySupportData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UWeaponImpactData> ImpactData;

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeapon : public AActor, public IGameplayCueInterface, public IFortDamageSourceInterface, public IFortAnalyticsInterface, public IFortSoundIndicatorInterface, public IFortTeamActorInterface, public IFortHolsterWeaponSourceInterface, public IActorSoundParameterInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsEquippingWeaponChangedDelegate, bool, bIsEquipping);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnModAddedToWeaponDelegate, UFortWeaponModItemDefinition*, Mod, AFortWeapon*, Weapon);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnModRemovedFromWeaponDelegate, UFortWeaponModItemDefinition*, Mod, AFortWeapon*, Weapon);

public:
	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool AllowReloadWhenFull() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="CosmeticWraps")
	FORTNITEGAME_API void AttemptApplyOverrideWrapToActor(AActor* Actor) const;

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API virtual void CancelActiveAbility();

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual bool CanFire(bool bPrimaryFire = true) const;

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void CheckPendingFire();

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientHandleReloadFromAbility();

	UFUNCTION(BlueprintCallable, Category="Reticle")
	FORTNITEGAME_API virtual FColor DetermineReticleColor();

	UFUNCTION(BlueprintPure, Category="CosmeticWraps")
	FORTNITEGAME_API bool DoesHaveOverrideWrap() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void EndCharge();

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetAccumulatedChargeTime() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TArray<UFortAlterationItemDefinition*> GetAlterations() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API int32 GetAmmoCostPerFire(float ChargePercentage = 0.000000f) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API FItemVariantHandle GetAmmoVariantHandle(const UFortWorldItemDefinition* AmmoItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API int32 GetBulletsPerClip() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetChargePercent() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetChargeTime() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetChargeToAutoDischarge() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetChargeToMinPercent() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API EFortWeaponCoreAnimation::Type GetCoreAnimation() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetCurrentMaxChargePercent() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual FVector GetDamageStartLocation(FVector& AimDir, int32 PatternIndex = -1) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetFiringRate() const;

	UFUNCTION(BlueprintPure, Category="Weapon HUD Data")
	FORTNITEGAME_API virtual const TArray<FWeaponHudData>& GetHudKeyActionData() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API FGuid GetInventoryGUID() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API const UFortItem* GetInventoryItem() const;

	UFUNCTION(BlueprintPure, Category="Charging")
	FORTNITEGAME_API bool GetIsChargingWeapon() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool GetIsReloadingWeapon() const;

	UFUNCTION(BlueprintPure, Category="Camera")
	FORTNITEGAME_API bool GetIsTargeting() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon", meta=(DeterminesOutputType="TemplateClass", DynamicOutputParam="TemplateObjs"))
	FORTNITEGAME_API bool GetItemTemplateObjects(TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled = true) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetLastFireTime() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual int32 GetLocalMagazineAmmoCount() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual int32 GetLocalRemainingAmmo() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual int32 GetMagazineAmmoCount() const;

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API float GetMeleeAttackPlayRate();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Effects")
	FORTNITEGAME_API FVector GetMuzzleLocation(int32 PatternIndex = -1) const;

	UFUNCTION(BlueprintPure, Category="Effects")
	FORTNITEGAME_API virtual FTransform GetMuzzleSocketTransform(int32 PatternIndex = -1) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon")
	FORTNITEGAME_API FText GetOutOfAmmoTextOverride();

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool GetPickupInstigatorData(int32& InstigatorHandle, FPickupInstigatorData& InstigatorData) const;

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API void GetPlayerActiveGrantedGameplayTags(FGameplayTagContainer& GameplayTags) const;

	UFUNCTION()
	FORTNITEGAME_API FFortPlayerAnimAssets GetPlayerAnimAssets() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API UProxyTable* GetPlayerAnimProxyTable() const;

	UFUNCTION()
	FORTNITEGAME_API FFortProceduralLayeringWeaponData GetProceduralLayeringData() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetProjectilePitchOffset() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetProjectileSpeed(float ChargePercent = 0.000000f) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetRange() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetReloadProgress() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetReloadTime() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual int32 GetRemainingAmmo() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	FORTNITEGAME_API virtual FColor GetReticleColor() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	FORTNITEGAME_API bool GetSupportsAutoFireAtReticleTargetMode() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetSurfaceRatioMultiplier(EPhysicalSurface HitSurface, const AActor* HitInstigator, const AActor* HitTarget) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual float GetTimeToNextFire() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API int32 GetTraceThroughPawnsLimit() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API FGuid GetTrackerGuid() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API UFortWeaponAdditiveAnimSet* GetWeaponAdditiveAnimSet() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API virtual EFortWeaponChargeStateForFireFX GetWeaponChargeStateForFireFX() const;

	UFUNCTION(BlueprintPure, Category="Data")
	FORTNITEGAME_API UFortWeaponItemDefinition* GetWeaponData() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API UFortWorldItemDefinition* GetWeaponDataAmmoWorldItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API void GetWeaponDataGameplayTags(FGameplayTagContainer& GameplayTags) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API EFortItemType GetWeaponDataItemType() const;

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API void GetWeaponDataPlayerGrantedGameplayTags(FGameplayTagContainer& GameplayTags) const;

	UFUNCTION(BlueprintPure, Category="Rarity")
	FORTNITEGAME_API EFortRarity GetWeaponDataRarity() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API TSoftObjectPtr<UTexture2D> GetWeaponDataSmallPreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API FSlateBrush GetWeaponDataSmallPreviewImageBrush() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	FORTNITEGAME_API EFortWeaponTriggerType::Type GetWeaponDataTriggerType() const;

	UFUNCTION(BlueprintPure, Category="Data")
	FORTNITEGAME_API FDataTableRowHandle GetWeaponDataWeaponStatHandle() const;

	UFUNCTION(BlueprintPure, Category="Visual")
	FORTNITEGAME_API USkeletalMeshComponentBudgeted* GetWeaponMesh() const;

	UFUNCTION(BlueprintPure, Category="Visual")
	FORTNITEGAME_API void GetWeaponMeshes(TArray<USkeletalMeshComponentBudgeted*>& WeaponMeshes) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API const TArray<FFortWeaponModSlot>& GetWeaponModSlots() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API UFortWeaponAnimSet* GetWeaponPawnAnimSet() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API float GetWeaponRateOfFireModifier();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Cosmetics")
	FORTNITEGAME_API void HandleBlueprintProbablyCosmeticStomp();

	UFUNCTION(BlueprintPure, Category="Weapon HUD Data")
	FORTNITEGAME_API bool HasAnyVisibleHudKeyActionData() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon", meta=(DisplayName="HasInfiniteAmmo"))
	FORTNITEGAME_API bool HasInfiniteAmmo() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool InventoryOwnerHasInfiniteAmmo() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsBeingEquipped() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsCosmeticLimited() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual bool IsEquipped() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual bool IsFiring() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool IsGauntlet() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual bool IsProjectileWeapon() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API virtual bool IsReloading() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool IsSuppressed() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool IsTargeting() const;

	UFUNCTION(BlueprintCallable, Category="FortWeapon", meta=(DisplayName="ConsumeAmmo"))
	FORTNITEGAME_API void K2_ConsumeAmmo(const int32 Quantity = 1, const bool bCheckInfiniteAmmo = false);

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon", meta=(DisplayName="OnLocalUnEquip"))
	FORTNITEGAME_API void K2_OnUnEquip();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API virtual void ModAmmo(int32 AmountToUse = -1);

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon")
	FORTNITEGAME_API void OnInstigatorSet();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnPawnMontageBlendingOut(UAnimMontage* PawnMontage, bool bInterrupted);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnPawnMontageStarted(UAnimMontage* PawnMontage);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_IsEquippingWeapon();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnSetTargeting(bool bNewIsTargeting);

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon")
	FORTNITEGAME_API void OnTetherDetached();

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon", meta=(DisplayName="OnEquippedAndAttached"))
	FORTNITEGAME_API void OnWeaponAttached();

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon", meta=(DisplayName="OnUnEquippedAndDetached"))
	FORTNITEGAME_API void OnWeaponDetached();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnWeaponMontageBlendingOut(UAnimMontage* WeaponMontage, bool bInterrupted);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnWeaponMontageStarted(UAnimMontage* WeaponMontage);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnWrapApplied(const UAthenaItemWrapDefinition* WrapDefinition);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API void PlayForceFeedback(bool bSecondaryFire, bool bPersistentFire, bool bImpact = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API virtual void PlayReloadFX(EFortReloadFXState::Type ReloadStage);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API virtual void PlayWeaponFireFX(bool bSecondaryFire = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortWeapon")
	FORTNITEGAME_API virtual void Reload();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void ResetTempWeaponMaterialOverride();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void RestoreOriginalMaterials();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetAllowReloadWhenFull(const bool bNewAllowReloadWhenFull);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetChargeTime(float InChargeTime);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API void SetFeedbackLinesDimFlag(bool bIsDimmed);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API bool SetHiddenInGameControllerOnly(USceneComponent* SceneComp, const bool NewHidden, const bool bPropagateToChildren = false);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API bool SetHiddenInGameOtherLocalControllersOnly(USceneComponent* SceneComp, const bool NewHidden, const bool bPropagateToChildren = false);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetIsReloadingWeapon(bool bReloading);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTrajectoryVisibility(const bool bNewVisible);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTrajectoryVisibilityControllerOnly(AFortPlayerController* FortPlayerController, const bool bNewVisible);

	UFUNCTION(BlueprintCallable, Category="Data")
	FORTNITEGAME_API void SetWeaponData(UFortWeaponItemDefinition* InWeaponData);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetWeaponVisibility(const bool bDesiredVisibility, const bool bForceUpdate = false);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetWeaponVisibilityControllerOnly(const bool bDesiredVisibility, const bool bForceUpdate = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API void StopForceFeedback();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API virtual void StopWeaponFireFX();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortWeapon")
	FORTNITEGAME_API bool TryReloadAmmoFromAbility();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void TryToCustomFire();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API virtual void UpdateDamageStartLocation();

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void UseWeaponDurability(float DurabilityScale = 1.000000f);

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API bool WeaponDataHasAnyMatchingGameplayTags(const FGameplayTagContainer TagContainer) const;

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API bool WeaponDataHasMatchingGameplayTag(const FGameplayTag TagToCheck) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool WeaponDataIsValid() const;

	UPROPERTY(BlueprintAssignable, Category="FortWeapon")
	FOnRateOfFireChanged OnWeaponRateOfFireChanged;

	UPROPERTY(BlueprintAssignable)
	FWeaponEventDelegate OnPressTrigger;

	UPROPERTY(BlueprintAssignable)
	FWeaponEventDelegate OnReleaseTrigger;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	float TimeToEquip;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsEquippingWeapon)
	bool bIsEquippingWeapon;

	UPROPERTY(BlueprintAssignable)
	FIsEquippingWeaponChangedDelegate IsEquippingWeaponChanged;

	UPROPERTY(Transient, Replicated)
	bool bIsReloadingWeapon;

	UPROPERTY(Transient, Replicated)
	bool bIsChargingWeapon;

	UPROPERTY(BlueprintReadOnly, Category="FortWeapon")
	bool bIsAimingConsumable;

	UPROPERTY(BlueprintAssignable)
	FOnLocalAmmoChanged OnLocalAmmoChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLocalReloadStarted OnLocalReloadStarted;

	UPROPERTY(BlueprintAssignable)
	FOnLocalReloadCancelled OnLocalReloadCancelled;

	UPROPERTY(BlueprintAssignable)
	FOnLocalTargetingChanged OnLocalTargetingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnTargetingChanged OnTargetingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnSecondaryAbilityToggled OnSecondaryAbilityToggled;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponVisibilityChanged OnVisibilityChanged;

	UPROPERTY(BlueprintAssignable)
	FWeaponEventDelegate OnWeaponFireAudio;

	UPROPERTY(BlueprintAssignable)
	FWeaponEventDelegate OnWeaponFireAudioVisuals;

	UPROPERTY(BlueprintAssignable)
	FOnModAddedToWeaponDelegate OnModAddedToWeapon;

	UPROPERTY(BlueprintAssignable)
	FOnModRemovedFromWeaponDelegate OnModRemovedFromWeapon;

	UPROPERTY(BlueprintAssignable)
	FOnConsumeAmmo OnConsumeAmmo;

	UPROPERTY(BlueprintAssignable)
	FOnReticleColorChanged OnReticleColorChanged;

	UPROPERTY(Config)
	bool bUseAttributeCaching;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedWeaponData)
	TObjectPtr<UFortWeaponItemDefinition> WeaponData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedCosmeticOverrideWeaponData)
	TObjectPtr<UFortWeaponItemDefinition> CosmeticOverrideWeaponData;

	UPROPERTY(EditAnywhere, Category="Effects")
	bool bImpactFXAttachedToHitActor;

	UPROPERTY(Transient)
	TArray<FFortGameplayAbilityBehaviorDistanceData> GameplayAbilityBehaviorDistanceData;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<UWeaponHitNotifyAudioBank> HitNotifyAudioBank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Sound Library", meta=(EditInline="true"))
	TObjectPtr<UFortSoundLibraryComponent> SoundLibraryComponent;

	UPROPERTY(BlueprintAssignable)
	FOnPlayImpactFX OnPlayImpactFXDelegate;

	UPROPERTY(BlueprintReadWrite, Category="FortWeapon")
	FOnBeamFired OnBeamFiredDelegate;

	UPROPERTY(EditAnywhere, Category="AnimationBudget")
	EFortWeaponReduceMeshWorkSetting WeaponReduceMeshWorkSetting;

	UPROPERTY(Config)
	float MaxWeaponSwitchNetworkWaitTime;

	UPROPERTY(Config)
	float MaxWeaponAttackNetworkWaitTime;

	UPROPERTY(Transient)
	float LastFireAbilityTime;

	UPROPERTY(BlueprintReadWrite, Category="FortWeapon")
	FOnGetWeaponAimRotOverride OnGetAimRotOverride;

	UPROPERTY(BlueprintAssignable, Category="Weapon HUD Data")
	FOnWeaponHudKeyActionUpdated OnWeaponHudKeyActionUpdated;

	UPROPERTY(EditDefaultsOnly, Category="Weapon HUD Data")
	TArray<FString> FeedbackLineActionIdsToDim;

	FORTNITEGAME_API virtual void GetActorSoundParams_Implementation(TArray<FAudioParameter>& Params) const override;

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	FORTNITEGAME_API float CalcConsumeSpeedMultiplierSafe() const;

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void ClearOverrideFireModeData();

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientGivenTo(APawn* P);

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientReportShotFlags(uint32 ShotFlags, int32 ShotIndex);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API virtual void GameplayCue_Impact(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_Weapons_Activation(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure, Category="Audio Parameter")
	FORTNITEGAME_API UAudioParameterComponent* GetAudioParameterComponent() const;

	UFUNCTION(BlueprintNativeEvent, Category="FortWeapon")
	FORTNITEGAME_API USoundBase* GetChargedWeaponFireSound(EFortWeaponSoundState::Type Channel, const bool bSecondaryFire) const;

	UFUNCTION(BlueprintPure, Category="CharacterAnimation")
	FORTNITEGAME_API UAnimMontage* GetEquipAnimation() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	FORTNITEGAME_API virtual FName GetMuzzleSocketName(int32 PatternIndex = 0) const;

	UFUNCTION(BlueprintPure, Category="CharacterAnimation")
	FORTNITEGAME_API UAnimMontage* GetReloadAnimation() const;

	UFUNCTION(BlueprintNativeEvent, Category="Weapon HUD Data")
	FORTNITEGAME_API bool GetReticleColorOverride(FColor& OutColor, const TArray<FHitResult>& HitResults) const;

	UFUNCTION(BlueprintPure, Category="Sound Library", meta=(CPP_Default_InComponentTag="()"))
	FORTNITEGAME_API UFortSoundLibraryComponent* GetSoundLibraryComponent(FGameplayTag InComponentTag) const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API int32 GetTraceThroughBuildingsLimit() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API int32 GetTraceThroughLandscapeLimit() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	FORTNITEGAME_API bool GetTraceThroughPawns() const;

	UFUNCTION(BlueprintPure, Category="WeaponAnimation")
	FORTNITEGAME_API UAnimMontage* GetWeaponEquipMontage() const;

	UFUNCTION(BlueprintPure, Category="WeaponAnimation")
	FORTNITEGAME_API UAnimMontage* GetWeaponReloadMontage() const;

	UFUNCTION(BlueprintPure, Category="Sounds")
	FORTNITEGAME_API bool IsQuartzGunfireEnabled() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnAmmoCountChanged();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnApplyFireModeData(UFortWeaponFireModeData* FireModeData);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnChargeDown();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnChargeUp();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnEndCharge();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnEquippedWeaponDestory();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnInitAlteration(UFortAlterationItemDefinition* NewAlteration);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnInitCosmeticAlterations(FFortCosmeticModification CosmeticMod);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnInitWeaponCosmetics();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnOutOfAmmoFire();

	UFUNCTION(BlueprintNativeEvent, Category="FortWeapon")
	FORTNITEGAME_API void OnPlayImpactFX(const FHitResult& HitResult, EPhysicalSurface ImpactPhysicalSurface, UFXSystemComponent* SpawnedPSC);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnPlayReloadFX(EFortReloadFXState::Type ReloadStage);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnPlayWeaponFireFX(bool bPersistentFire, bool bSecondaryFire);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="On Local Client Reached Max Charge"))
	FORTNITEGAME_API void OnReachedMaxCharge();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnReachedMaxChargeForCurAmmo();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="On Local Client Reached Min Charge"))
	FORTNITEGAME_API void OnReachedMinCharge();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnRemoteClientReachedMaxCharge();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnRemoteClientReachedMinCharge();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_AmmoCount(int32 OldAmmoCount);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ChargeStatusPack();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_EquippedWeaponDestroyWrapper();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_LastFireTimeVerified();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_PhantomReserveAmmo();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_PrimaryAbilitySpecHandle();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ReplicatedAppliedAlterations();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ReplicatedCosmeticOverrideWeaponData();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ReplicatedWeaponData();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ReplicatedWeaponModSlots(const TArray<FFortWeaponModSlot>& PreviousModSlots);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStartCharge();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnStopWeaponFireFX();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnWeaponVisibilityChanged(bool bVisible, bool bSetForLocalControllerOnly);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API virtual void PlayNativeImpactFX(const FHitResult& HitResult, const FGameplayCueParameters& GameplayCueParameters);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void PlayWeaponFireCustomAudio(bool bPersistentFire, bool bSecondaryFire);

	UFUNCTION(BlueprintCallable, Category="CharacterAnimation")
	FORTNITEGAME_API void ResetPlayerAnimAssetOverride();

	UFUNCTION(BlueprintCallable, Category="CharacterAnimation")
	FORTNITEGAME_API void ResetWeaponCoreAnimOverride();

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerResetShotReport();

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerSetChargeState(uint8 NewState);

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void SetBase3PCamera(const TSubclassOf<UFortCameraMode>& NewBaseCam);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortWeapon")
	FORTNITEGAME_API void SetFireSoundPitchMultiplier(const float NewPitch);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API bool SetHudKeyActionDescription(int32 Index, FText InActionDescription);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API bool SetHudKeyActionDescriptionByID(const FString& KeyActionId, FText InActionDescription);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API void SetHudKeyActionsVisibility(const TArray<FWeaponHudKeyActionVisibility>& IndexVisibilityArray);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API bool SetHudKeyActionVisibility(int32 Index, bool bVisible);

	UFUNCTION(BlueprintCallable, Category="Weapon HUD Data")
	FORTNITEGAME_API bool SetHudKeyActionVisibilityByID(const FString& KeyActionId, bool bVisible);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetNativeChargeUpEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetOverrideFireModeData(const TSoftObjectPtr<UFortWeaponFireModeData>& OverrideFireModeData);

	UFUNCTION(BlueprintCallable, Category="CharacterAnimation")
	FORTNITEGAME_API void SetPlayerAnimAssetOverride(FFortPlayerAnimAssets InPlayerAnimAssetsOverride, bool bResetOnUnequip);

	UFUNCTION(BlueprintCallable, Category="Reticle")
	FORTNITEGAME_API void SetShouldDrawNativeReticle(bool bInShouldDrawReticle);

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void SetTargeting3PCamera(const TSubclassOf<UFortCameraMode>& NewTargetingCam);

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void SetTargetingReload3PCamera(const TSubclassOf<UFortCameraMode>& NewTargetingReloadCam);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTraceThroughBuildingsLimit(int32 NewTraceThroughBuildingsLimit);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTraceThroughLandscapeLimit(int32 NewTraceThroughTerrainLimit);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTraceThroughPawns(bool bNewTraceThroughPawns);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	FORTNITEGAME_API void SetTraceThroughPawnsLimit(int32 NewTraceThroughPawnsLimit);

	UFUNCTION(BlueprintCallable, Category="CharacterAnimation")
	FORTNITEGAME_API void SetWeaponCoreAnimOverride(EFortWeaponCoreAnimation::Type InWeaponCoreAnimationOverride);

	UFUNCTION(BlueprintCallable, Category="CharacterAnimation")
	FORTNITEGAME_API void SetWeaponPawnAnimsetOverride(UFortWeaponAnimSet* WeaponPawnAnimsetOverride);

	UFUNCTION(BlueprintNativeEvent, Category="FortWeapon")
	FORTNITEGAME_API bool ShouldCustomTriggerPerformPendingFire() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void StartCharge();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void StopWeaponFireCustomAudio();

	UPROPERTY(ReplicatedUsing=OnRep_EquippedWeaponDestroyWrapper)
	uint8 EquippedWeaponDestroyWrapperRepCounter;

	UPROPERTY(Transient)
	float PersistentFXStartTime;

	UPROPERTY(EditAnywhere, Category="Effects")
	float MinimumTimeForPersistentFX;

	UPROPERTY(Transient)
	TSoftObjectPtr<UAthenaItemWrapDefinition> OverrideItemWrapSoftPtr;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	bool bWeaponSupportsQuartzGunfire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Sounds", meta=(EditCondition="bWeaponSupportsQuartzGunfire", EditConditionHides, EditInline="true"))
	TObjectPtr<UFortQuartzGunfireComponent> QuartzGunfireComp;

	UPROPERTY(EditAnywhere, Category="Reticle")
	bool bShouldDrawNativeReticle;

	UPROPERTY(EditAnywhere, Category="Reticle")
	bool bShouldAlwaysDrawNativeMuzzleBlockedIndicator;

	UPROPERTY(EditAnywhere, Category="Reticle")
	bool bShouldForceCheckCollisions;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> AutoFireReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	FColor ReticleDefaultColor;

	UPROPERTY(EditAnywhere, Category="Reticle")
	FColor ReticleEnemyColor;

	UPROPERTY(EditAnywhere, Category="Reticle")
	FColor ReticleBuildingColor;

	UPROPERTY(EditAnywhere, Category="Reticle")
	FColor ReticleNoTargetColor;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> HitNotifyReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> HitNotifyLocationReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> CriticalHitNotifyLocationReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleCenterImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleCenterPerfectAimImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleInvalidTargetImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> MuzzleBlockedReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleAltCenterImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleOuterImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UTexture2D> ReticleAltOuterImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	float ReticleDefaultPrimaryStrikeAngle;

	UPROPERTY(EditAnywhere, Category="Reticle")
	float ReticleDefaultSecondaryStrikeAngle;

	UPROPERTY(EditAnywhere, Category="Reticle")
	bool bSupportsAutofireAtReticleTarget;

	UPROPERTY(EditAnywhere, Category="FireMode")
	bool bSupportsTapToFireMode;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<UFortCameraMode> CameraBase3PClass;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<UFortCameraMode> CameraTargeting3PClass;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<UFortCameraMode> CameraTargeting3PReloadClass;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<UFortCameraMode> CameraBase1PClass;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<UFortCameraMode> CameraTargeting1PClass;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> DestroyedSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> OutOfAmmoSound;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortReloadFXState"))
	TObjectPtr<USoundBase> ReloadSounds[3];

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> PrimaryFireSound1P;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundState"))
	TObjectPtr<USoundBase> PrimaryFireSound[3];

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> PrimaryFireStopSound1P;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundState"))
	TObjectPtr<USoundBase> PrimaryFireStopSound[3];

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundState"))
	TObjectPtr<USoundBase> SecondaryFireSound[3];

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundState"))
	TObjectPtr<USoundBase> SecondaryFireStopSound[3];

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponChargeStateForFireFX"))
	TObjectPtr<USoundBase> ChargeFireSound1P[3];

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponChargeStateForFireFX"))
	TObjectPtr<USoundBase> ChargeFireSound[3];

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> TargetingStartSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> TargetingEndSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	float PrimaryFireSoundFadeOutTime;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<USoundBase> ImpactPhysicalSurfaceSounds[35];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<UParticleSystem> ImpactPhysicalSurfaceEffects[35];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TArray<TObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffectAssets;

	UPROPERTY(EditAnywhere, Category="Effects")
	FFortNDCImpactInfo NDCImpactFX;

	UPROPERTY(Transient)
	TArray<FWeaponImpactArraySupportData> ImpactArraySupportData;

	UPROPERTY(EditAnywhere, Category="Effects")
	TSubclassOf<ULegacyCameraShake> ImpactCameraShake;

	UPROPERTY(BlueprintReadWrite, Category="Effects")
	TObjectPtr<UForceFeedbackEffect> PrimaryForceFeedbackEffect;

	UPROPERTY(EditAnywhere, Category="Effects")
	TObjectPtr<UForceFeedbackEffect> SecondaryForceFeedbackEffect;

	UPROPERTY(EditAnywhere, Category="Effects")
	TObjectPtr<UForceFeedbackEffect> PrimaryImpactForceFeedbackEffect;

	UPROPERTY(EditAnywhere, Category="Effects")
	TObjectPtr<UForceFeedbackEffect> SecondaryImpactForceFeedbackEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Sound Indicator", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(Transient)
	int32 CurrentGunFireIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visual", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> WeaponMesh;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USkeletalMeshComponentBudgeted>> AllWeaponMeshes;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> DefaultWeaponMaterials;

	UPROPERTY(Transient)
	TMap<TObjectPtr<USkeletalMeshComponentBudgeted>, FMaterialInterfaceArray> OriginalMaterialMap;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundChannel"))
	int32 FireAudioChannelWantsToPlay[4];

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames"))
	int32 WrapSectionMask;

	UPROPERTY(Transient)
	bool bUsingSecondaryFireAudio;

	UPROPERTY(Transient)
	bool bHasCachedAdditionalMeshes;

	UPROPERTY(Transient)
	FColor CurrentReticleColor;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality")
	FFortEffectDistanceQuality FireFXSignificance;

	UPROPERTY(Transient)
	float LastFireTime;

	UPROPERTY(ReplicatedUsing=OnRep_LastFireTimeVerified)
	float LastFireTimeVerified;

	UPROPERTY(Transient)
	uint8 bIsPlayingFireFX : 1;

	UPROPERTY(Transient)
	uint8 bFireFXTriggered : 1;

	UPROPERTY(Transient)
	uint8 bWeaponFireCustomAudioTriggered : 1;

	UPROPERTY(EditAnywhere, Category="Camera")
	uint8 bAllowTargeting : 1;

	UPROPERTY(EditAnywhere, Category="Camera")
	uint8 bExitTargetingWhenPrimaryIsFired : 1;

	UPROPERTY()
	uint8 bIsTargeting : 1;

	UPROPERTY(EditAnywhere, Category="Camera")
	uint8 bForceCameraTargetSource : 1;

	UPROPERTY()
	uint8 bTraceThroughPawns : 1;

	UPROPERTY()
	uint8 bTraceThroughWorld : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bUseProjectileTrace : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bUseVariableFocalDistanceTargeting : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bUseWeaponTraceForReticle : 1;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	uint8 bAllowReloadWhenFull : 1;

	UPROPERTY(Transient)
	bool bIsInReleaseSecondaryFireScope;

	UPROPERTY(Transient)
	float TimerIntervalAdjustment;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	float InputQueueTimePercent;

	UPROPERTY()
	float LastTargetingTransitionTime;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector TargetSourceOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector TargetSourceOffsetWhileCrouched;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector TargetSourceOffsetWhileTargeting;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	int32 TraceThroughPawnsLimit;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	int32 TraceThroughBuildingsLimit;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	int32 TraceThroughLandscapeLimit;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	float ProjectilePitchOffset;

	UPROPERTY(Transient)
	float LastReloadTime;

	UPROPERTY(Transient)
	float LastSuccessfulReloadTime;

	UPROPERTY(Transient)
	float CurrentReloadDuration;

	UPROPERTY(Transient, Replicated)
	FGuid ItemEntryGuid;

	UPROPERTY(Transient, Replicated)
	FGuid TrackerGuid;

	UPROPERTY(Transient, Replicated)
	int32 WeaponLevel;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AmmoCount)
	int32 AmmoCount;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PhantomReserveAmmo)
	int32 PhantomReserveAmmo;

	UPROPERTY(Transient)
	int32 BurstFireCounter;

	UPROPERTY(Transient)
	float ChargeTime;

	UPROPERTY(Transient)
	float AccumulatedChargeTime;

	UPROPERTY(Transient)
	float LastChargeTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Charging", meta=(Categories="GameplayCue"))
	FGameplayTag StartChargeGameplayCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Charging", meta=(Categories="GameplayCue"))
	FGameplayTag MaxChargeGameplayCue;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	FGameplayTag OutOfAmmoTextOverrideFailTag;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	FGameplayTag NoSpareAmmoToReloadTextOverrideFailTag;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	FGameplayTagQuery FireCanInterruptEquipQuery;

	UPROPERTY()
	int32 CurrentShotLogIndex;

	UPROPERTY(Transient)
	TArray<uint32> ShotLogFlags;

	UPROPERTY(Transient)
	uint8 bInitializedWeaponItem : 1;

	UPROPERTY(Transient)
	uint8 bPendingDestroyDueToDurabilityOrStackCount : 1;

	UPROPERTY(Transient)
	uint8 bCompletedAppliedAlterationsLoad : 1;

	UPROPERTY(Transient)
	uint8 bCompletedWeaponLoad : 1;

	UPROPERTY(Transient)
	uint8 bIsCosmeticLimited : 1;

	UPROPERTY(Transient)
	uint8 bIsCosmeticGatedLocally : 1;

	UPROPERTY(Transient)
	uint8 bReplicatedAppliedAlterationsWithNoInstigator : 1;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	uint8 bShouldFullyApplyVariantsOnEquip : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bSecondaryFireAlwaysCancelSwimSprint : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bEnableNativeChargeUp : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeapon")
	uint8 bShowWhenHolstered : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeapon", meta=(EditCondition="!bShowWhenHolstered"))
	TArray<TEnumAsByte<EFortCustomPartType::Type>> CustomPartsToShowWhenHolstered;

	UPROPERTY(ReplicatedUsing=OnRep_ChargeStatusPack)
	int16 ChargeStatusPack;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortProjectileTrajectory> AttachedTrajectoryIndicator;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortGameplayAbility> ActiveAbility;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PrimaryAbilitySpecHandle)
	FGameplayAbilitySpecHandle PrimaryAbilitySpecHandle;

	UPROPERTY(Transient, Replicated)
	FGameplayAbilitySpecHandle SecondaryAbilitySpecHandle;

	UPROPERTY(Transient, Replicated)
	FGameplayAbilitySpecHandle ReloadAbilitySpecHandle;

	UPROPERTY(Transient, Replicated)
	FGameplayAbilitySpecHandle ImpactAbilitySpecHandle;

	UPROPERTY(Transient, Replicated)
	FGameplayAbilitySpecHandle ReticleTraceOverrideSpecHandle;

	UPROPERTY(Transient)
	TArray<FGameplayAbilitySpecHandle> EquippedAbilityHandles;

	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> EquippedAbilitySetHandles;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedAppliedAlterations)
	TArray<TObjectPtr<UFortAlterationItemDefinition>> AppliedAlterations;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedWeaponModSlots)
	TArray<FFortWeaponModSlot> WeaponModSlots;

	UPROPERTY(Transient)
	TArray<FFortEquippedWeaponModSlot> EquippedWeaponModSlots;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponModRuntimeData> ModRuntimeDataCache;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponModDebugComponent> ModDebugComp;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponOpticDefinition> OpticDefinition;

	UPROPERTY(Transient)
	FCosmeticVariantCache PreviousWeaponVariants;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaItemWrapDefinition> AppliedItemWrap;

	UPROPERTY(Transient)
	TObjectPtr<AFortFXManager> CachedFXManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortSignificanceManager> CachedSignificanceManager;

	UPROPERTY(EditAnywhere, Category="Effects")
	FName MuzzleSocketName;

	UPROPERTY(EditAnywhere, Category="Effects")
	FName MuzzleFalloffSocketName;

	UPROPERTY(EditAnywhere, Category="AttachmentOverride")
	FName WeaponHandSocketNameOverride;

	UPROPERTY(EditAnywhere, Category="AttachmentOverride")
	FName LeftHandWeaponHandSocketNameOverride;

	UPROPERTY(EditAnywhere, Category="AttachmentOverride")
	TArray<TEnumAsByte<EFortCustomPartType::Type>> WeaponHandSocketPartOverrides;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bForceOverrideGenerateOverlapEvents : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponMods", meta=(ForceInlineRow))
	TMap<FGameplayTag, TObjectPtr<UAnimSequence>> ModLeftHandPoseOffsets;

	UPROPERTY(EditDefaultsOnly, Category="WeaponMods", meta=(ForceInlineRow))
	TMap<FGameplayTag, FWeaponModReloadAnimData> ModReloadAnimData;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> EquipAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> ReloadAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TArray<TObjectPtr<UAnimMontage>> CustomReloadAnimationPerAmmoToFill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> PrimaryAbilityAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> SecondaryAbilityAnimation;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponEquipMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponReloadMontage;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TArray<TObjectPtr<UAnimMontage>> CustomWeaponReloadMontagePerAmmoToFill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponPrimaryAbilityMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponSecondaryAbilityMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FirstPerson")
	TObjectPtr<UFortWeaponFirstPersonData> FirstPersonData;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimSequence> PoseOffsetAnimSequence;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimSequence> PoseOffsetAnimSequenceFemaleOverride;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnimation;

	UPROPERTY(Transient)
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnimationOverride;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UFortWeaponAnimSet> WeaponPawnAnimSet;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	FFortPlayerAnimAssets PlayerAnimAssets;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	FFortProceduralLayeringWeaponData ProceduralLayeringData;

	UPROPERTY(Transient)
	FFortPlayerAnimAssets PlayerAnimAssetsOverride;

	UPROPERTY(Transient)
	bool bResetAnimAssetsOverrideOnUnEquip;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TSubclassOf<UAnimInstance> WeaponPawnAnimLayerOverlayClass;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UFortWeaponAdditiveAnimSet> WeaponAdditiveAnimSet;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UProxyTable> PlayerAnimProxyTable;

	UPROPERTY()
	TObjectPtr<UFortWeaponAnimSet> WeaponPawnAnimsetOverride;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> UnableToPerformActionMontageOverride;

	UPROPERTY(Transient)
	TSoftObjectPtr<UFortWeaponFireModeData> ActiveFireMode;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	TSoftObjectPtr<UFortWeaponFireModeData> FireModeData_HipFire;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	TSoftObjectPtr<UFortWeaponFireModeData> FireModeData_AimDownSight;

	UPROPERTY()
	TSoftObjectPtr<UFortWeaponFireModeData> FireModeData_Override;

	UPROPERTY(Transient)
	TObjectPtr<AActor> LockOnTargetCandidate;

	UPROPERTY(Transient)
	bool bIgnoreTryToFireSlotCooldownRestriction;

	UPROPERTY(EditDefaultsOnly, Category="Analytics")
	bool bFireConsumableAnalyticEvent;

	UPROPERTY(EditDefaultsOnly, Category="Weapon HUD Data")
	TArray<FWeaponHudData> HudKeyActionData;

private:
	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void ShowWeaponFireAudioVisual();

	UPROPERTY(Transient, Replicated)
	bool bDisableEquipAnimation;

	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Deprecated in favor of GrantedAbilityRemovalPolicy array to allow more flexibility."))
	bool bRemoveAbilitiesWhenRemovedFromInventory;

	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponAbilityRemovalReason"))
	EFortWeaponAbilityRemovalPolicy GrantedAbilityRemovalPolicy[3];

	UPROPERTY(Transient)
	TArray<TObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffectInstances;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortGenericDataStoreManagerComponent> DataStoreManager;

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundChannel", EditInline="true"))
	TObjectPtr<UAudioComponent> FireAudioChannels[4];

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortReloadFXState", EditInline="true"))
	TObjectPtr<UAudioComponent> ReloadAudioChannels[3];

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortTargetingFXState", EditInline="true"))
	TObjectPtr<UAudioComponent> TargetingAudioChannels[2];

	UPROPERTY(Transient)
	FVector CurrentDamageStartLocation;

	UPROPERTY(Transient)
	FVector CurrentAdjustedAimDirection;

	UPROPERTY(Transient)
	TObjectPtr<ACustomItemWrapModifier> ItemWrapModifier;

};

UCLASS()
class UWeaponImpactData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> ImpactEffect;

};

