// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/FortCosmeticOverlayMaterialTypes.h"
#include "Creative/FortCreativeTags.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortWeaponEnums.h"
#include "Items/FortItemDefinitionAbilitySetInterface.h"
#include "Items/FortItemEntry.h"
#include "Items/FortWorldItemDefinition.h"
#include "Weapons/Data/FortWeaponModSlot.h"
#include "FortWeaponItemDefinition.generated.h"

class AFortWeapon;
class UAnimMontage;
class UAthenaCosmeticItemDefinition;
class UAthenaItemWrapDefinition;
class UCurveFloat;
class UCurveTable;
class UCustomCharacterPart;
class UDataTable;
class UFortAbilitySet;
class UFortAlterationItemDefinition;
class UFortGameplayAbility;
class UFortWeaponAdditionalData;
class UFortWorldItem;
class UFortWorldItemDefinition;
class UMaterialInterface;
class USkeletalMesh;
class USoundLibrary;
class UTexture2D;
enum class EFortDisplayTier : uint8;

UENUM()
enum class EFortDisplayTier : uint8
{
	Invalid = 0,
	Handmade = 1,
	Copper = 2,
	Silver = 3,
	Malachite = 4,
	Obsidian = 5,
	Brightcore = 6,
	Spectrolite = 7,
	Shadowshard = 8,
	Sunbeam = 9,
	Moonglow = 10,
};

USTRUCT(BlueprintType)
struct FFortBaseWeaponStats : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 BaseLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName NamedWeightRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DmgPB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DmgMid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DmgLong;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DmgMaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EnvDmgPB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EnvDmgMid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EnvDmgLong;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EnvDmgMaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ImpactDmgPB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ImpactDmgMid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ImpactDmgLong;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ImpactDmgMaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	bool bForceControl;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float RngPB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float RngMid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float RngLong;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float RngMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	TObjectPtr<UCurveTable> DmgScaleTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName DmgScaleTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DmgScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	TObjectPtr<UCurveTable> EnvDmgScaleTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName EnvDmgScaleTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EnvDmgScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	TObjectPtr<UCurveTable> ImpactDmgScaleTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName ImpactDmgScaleTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ImpactDmgScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName SurfaceRatioRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DamageZone_Light;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DamageZone_Normal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DamageZone_Critical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DamageZone_Vulnerability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DamageZone_Invulnerability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float KnockbackMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MidRangeKnockbackMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float LongRangeKnockbackMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float KnockbackZAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ShortRangeHitImpulseMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MidRangeHitImpulseMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float LongRangeHitImpulseMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float HitImpulseZBias;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float StunTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float StunScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	TObjectPtr<UDataTable> Durability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FName DurabilityRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DurabilityScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DurabilityPerUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float FullChargeDurabilityPerUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DiceCritChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float DiceCritDamageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ReloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ReloadScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	EFortWeaponReloadType ReloadType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	bool bAllowReloadInterrupt;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	bool bReloadInterruptIsImmediate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 NumIndividualBulletsToReload;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 ClipSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ClipScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 InitialClips;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	bool bShouldAddInitialAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 CartridgePerFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 AmmoCostPerFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	int32 MaxAmmoCostPerFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MinChargeTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MaxChargeTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float ChargeDownTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	bool bAutoDischarge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats", meta=(EditCondition="bAutoDischarge"))
	float MaxChargeTimeUntilDischarge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MinChargeDamageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float MaxChargeDamageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	TObjectPtr<UCurveFloat> ChargeDamageMultiplierCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float EquipAnimRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float QuickBarSlotCooldownDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float AimAssistPullStrengthMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	float AimAssistSlowStrengthMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseWeaponStats")
	FGameplayTag MeleeAimAssistRequiredTag;

};

USTRUCT(BlueprintType)
struct FFortHarvestingToolMontageOverrideData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortHarvestingToolMontageOverrideData")
	FGameplayTag CosmeticTag;

	UPROPERTY(EditAnywhere, Category="FortHarvestingToolMontageOverrideData")
	TSoftObjectPtr<UAnimMontage> MontageToPlay;

};

USTRUCT(BlueprintType)
struct FFortHarvestingToolMontageOverrides
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortHarvestingToolMontageOverrides")
	TArray<FFortHarvestingToolMontageOverrideData> MontageOverrideData;

};

USTRUCT(BlueprintType)
struct FFortWeaponDurabilityByRarityStats : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Common;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Uncommon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Rare;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Epic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Legendary;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Mythic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Transcendent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DurabilityStats")
	int32 Unattainable;

};

UCLASS(Abstract, EditInlineNew)
class UFortWeaponAdditionalData : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortWeaponItemDefinition : public UFortWorldItemDefinition, public IFortCreativeTagsBearer, public IFortItemDefinitionAbilitySetInterface, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool AllowSecondaryFireToInterruptPrimary() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool AlwaysChargeUpToMin() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	const TArray<FName>& GetAnalyticTags() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	UFortAlterationItemDefinition* GetBaseAlteration() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	UFortAlterationItemDefinition* GetBaseCosmeticAlteration() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	float GetDegradedPercentage() const;

	UFUNCTION(BlueprintPure, Category="Weapon Item Definition")
	EFortDisplayTier GetDisplayTier() const;

	UFUNCTION(BlueprintPure, Category="Weapon Item Definition")
	static FText GetDisplayTierAsText(const EFortDisplayTier DisplayTier);

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TArray<TSubclassOf<UFortGameplayAbility>> GetEquippedAbilities() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	float GetHitNotifyDuration() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	float GetLowAmmoPercentage() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetOnHitAbility() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetPrimaryFireAbility() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetReloadAbility() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	FVector2D GetReticleCenterImageOffset() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	const TArray<float>& GetReticleCornerAngles() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetSecondaryFireAbility() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	EFortWeaponTriggerType::Type GetSecondaryTriggerType() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FText GetShortDisplayName() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	EFortWeaponTriggerType::Type GetTriggerType() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool GetUsesCustomAmmoType() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<AFortWeapon> GetWeaponActorClass() const;

	UFUNCTION(BlueprintPure, Category="WeaponMeleeItemDefinition")
	TArray<TSoftObjectPtr<UMaterialInterface>> GetWeaponMaterialOverrides() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	USkeletalMesh* GetWeaponMeshOverride() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	float GetWeaponRechargeAmmoQuantity(const int32 InLevel = 0) const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	float GetWeaponRechargeAmmoRate(const int32 InLevel = 0) const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	FDataTableRowHandle GetWeaponStatHandle() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	const bool HasAmmo() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	const bool HasUniqueAmmo() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Weapon Item Definition")
	static void InitializeAlterationsBasedOnLootLevel(UPARAM(ref) FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool NoFireOnReleaseBeforeMinChargeTime() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool ShouldAllowTargetingDuringReload() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool ShouldEndAbilityOnChargeEnd() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool ShouldShowAmmoAsPercent() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool ShouldUpdateLastFireTimeOnDischarge() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool TargetingPreventsReload() const;

	UFUNCTION(BlueprintCallable, Category="WeaponItemDefinition")
	bool TryGetBaseClipSizeWithMods(UFortWorldItem* WeaponWorldItem, int32& OutClipSize);

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	bool UsesPhantomReserveAmmo() const;

	UPROPERTY(EditDefaultsOnly, Category="SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> WeaponSoundLibraries;

	UPROPERTY(EditDefaultsOnly, Category="SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> WeaponOwnerSoundLibraries;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AllowedClasses="/Script/Engine.Material,/Script/Engine.MaterialInstance", AssetBundles="EquippedCosmetic"))
	TArray<TSoftObjectPtr<UMaterialInterface>> WeaponMaterialOverrides;

protected:
	UPROPERTY(EditAnywhere, Category="WeaponData Effects", meta=(AssetBundles="Equipped,ClientAthenaPreload,ServerAthenaPreload"))
	TSoftClassPtr<AFortWeapon> WeaponActorClass;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<USkeletalMesh> WeaponMeshOverride;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<UAthenaItemWrapDefinition> IntrinsicOverrideWrap;

	UPROPERTY(EditAnywhere, Category="WeaponData")
	FFortCosmeticOverlayMaterialData OverlayMaterialData;

	UPROPERTY(EditAnywhere, Category="WeaponData")
	FDataTableRowHandle WeaponStatHandle;

	UPROPERTY(EditAnywhere, Category="WeaponData | RechargeAmmo")
	FScalableFloat WeaponRechargeAmmoRate;

	UPROPERTY(EditAnywhere, Category="WeaponData | RechargeAmmo")
	FScalableFloat WeaponRechargeAmmoQuantity;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData | Ability Sets", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload"))
	TSoftObjectPtr<UFortAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Alterations")
	FName AlterationSlotsLoadoutRow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Alterations")
	FName BaselineAlterationSlotsLoadoutRow;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortAlterationItemDefinition> BaseAlteration;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftObjectPtr<UFortAlterationItemDefinition> BaseCosmeticAlteration;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TArray<FFortWeaponModSlot> WeaponModSlots;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload,ItemDetails"))
	TSoftClassPtr<UFortGameplayAbility> PrimaryFireAbility;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<UFortGameplayAbility> SecondaryFireAbility;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<UFortGameplayAbility> ReloadAbility;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<UFortGameplayAbility> OnHitAbility;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TArray<TSoftClassPtr<UFortGameplayAbility>> EquippedAbilities;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemsInInventoryInZone,ItemDetailsClientAthenaPreload,ClientAthenaPreload"))
	TSoftObjectPtr<UFortAbilitySet> EquippedAbilitySet;

	UPROPERTY(EditDefaultsOnly, Category="Abilities - Cosmetic")
	TArray<TObjectPtr<UCustomCharacterPart>> EquippedCharacterParts;

	UPROPERTY(EditAnywhere, Category="Ammo", meta=(AssetBundles="Equipped,ClientAthenaPreload,ItemDetails"))
	TSoftObjectPtr<UFortWorldItemDefinition> AmmoData;

	UPROPERTY(EditAnywhere, Instanced, Category="WeaponData")
	TArray<TObjectPtr<UFortWeaponAdditionalData>> AdditionalDataFields;

	UPROPERTY(EditAnywhere, Category="Ammo")
	float LowAmmoPercentage;

	UPROPERTY(EditAnywhere, Category="Firing")
	TEnumAsByte<EFortWeaponTriggerType::Type> TriggerType;

	UPROPERTY(EditAnywhere, Category="Firing")
	TEnumAsByte<EFortWeaponTriggerType::Type> SecondaryTriggerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	EFortDisplayTier DisplayTier;

	UPROPERTY(EditAnywhere, Category="WeaponData | RechargeAmmo")
	uint8 bRechargeAmmoToClip : 1;

	UPROPERTY(EditAnywhere, Category="Ammo")
	uint8 bUsesPhantomReserveAmmo : 1;

	UPROPERTY(EditAnywhere, Category="Ammo")
	uint8 bUsesCustomAmmoType : 1;

	UPROPERTY(EditAnywhere, Category="Ammo")
	uint8 bShowAmmoAsPercent : 1;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bShouldMagazineSizeDisplayInfinity : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bAllowSecondaryFireToInterruptPrimary : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bAllowTargetingDuringReload : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bTargetingPreventsReload : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bCanFireWhileInstigatorTethered : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bCanFireWhileNotTargetedInVehicle : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bAlwaysChargeUpToMin : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bNoFireOnReleaseBeforeMinChargeTime : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bEndAbilityOnChargeEnd : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bUpdateLastFireTimeOnDischarge : 1;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(DisplayAfter="ReticleInvalidTargetImage"))
	uint8 bReticleCornerOutsideSpreadRadius : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bValidForLastEquipped : 1;

	UPROPERTY(EditAnywhere, Category="WeaponData")
	uint8 bRequestClientPreload : 1;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic", DisplayAfter="WeaponMeshOverride"))
	uint8 bEnableWeaponMeshOverrideUpdates : 1;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(DisplayAfter="ReticleInvalidTargetImage"))
	float HitNotifyDuration;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(AssetBundles="Equipped,ClientCampaign,ClientAthenaPreload"))
	TSoftObjectPtr<UTexture2D> ReticleImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	TArray<float> ReticleCornerAngles;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(AssetBundles="Equipped,Client"))
	TSoftObjectPtr<UTexture2D> ReticleCenterImage;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(AssetBundles="Equipped,Client"))
	TSoftObjectPtr<UTexture2D> ReticleCenterPerfectAimImage;

	UPROPERTY(EditAnywhere, Category="Reticle")
	FVector2D ReticleCenterImageOffset;

	UPROPERTY(EditAnywhere, Category="Reticle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UTexture2D> ReticleInvalidTargetImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Analytics")
	FGameplayTagContainer AnalyticTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer PlayerGrantedGameplayTags;

	UPROPERTY()
	TArray<FName> ActualAnalyticFNames;

#if WITH_EDITORONLY_DATA
	UPROPERTY(AssetRegistrySearchable)
	TArray<FName> ActualGameplayTagFNames;
#endif

	UPROPERTY(EditAnywhere, Category="WeaponItemDefinition", meta=(AssetBundles="AvatarDisplay"))
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> RequiredWeaponParent;

	UPROPERTY(EditAnywhere, Category="BoneSetsToHide")
	FGameplayTagContainer BoneSetsToHide;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

	UPROPERTY(Instanced)
	TObjectPtr<UFortWeaponAdditionalData> AdditionalData;

};

