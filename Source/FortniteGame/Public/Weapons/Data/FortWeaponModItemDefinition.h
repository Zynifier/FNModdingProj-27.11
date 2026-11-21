// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/FortAbilityTypes.h"
#include "Items/FortItemDefinitionItemModifierInterface.h"
#include "Items/FortWorldItemDefinition.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "Weapons/Data/FortWeaponRangedItemDefinition.h"
#include "FortWeaponModItemDefinition.generated.h"

class AFortWeapon;
class UAnimMontage;
class UDataTable;
class UFortAbilitySet;
class UFortWeaponFirstPersonData;
class UGameplayEffect;
class USoundBase;
class UStaticMeshComponent;

USTRUCT()
struct FFortTrackedModStaticMeshData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ModStaticMeshComp;

};

USTRUCT()
struct FFortTrackedModSubweaponList
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<AFortWeapon*> SpawnedWeapons;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortWeaponModItemDefinition : public UFortWorldItemDefinition, public IFortItemDefinitionItemModifierInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponModItemDefinition", meta=(Categories="WeaponMod.Slot"))
	FGameplayTag ModSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, DuplicateTransient, Category="WeaponModGameplay")
	FGameplayTag PluginTuningTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, DuplicateTransient, Category="WeaponModGameplay")
	FWeaponModCosmeticData DefaultModData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer PlayerGrantedGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModGameplay", meta=(DisplayName="Additional Conditional Include Tags"))
	TArray<FFortConditionalIncludeTags> AdditionalGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModGameplay", meta=(AssetBundles="ItemsInInventoryInZone"))
	TSoftObjectPtr<UFortAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponModGameplay")
	uint8 bEnableWeaponRangedHitGameplayEvent : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponModItemDefinition")
	uint8 bDisplayModOnWeaponPickupUI : 1;

	UPROPERTY(VisibleAnywhere, Category="Tuning")
	FGameplayTag WeaponTuningPrefixTag;

	UPROPERTY(EditDefaultsOnly, Category="Tuning")
	FGameplayTagQuery AllowedWeaponTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Tuning")
	FGameplayTag WeaponModTag;

	UPROPERTY(EditDefaultsOnly, Category="Tuning")
	TObjectPtr<UDataTable> WeaponModDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Tuning")
	TSubclassOf<UGameplayEffect> WeaponModBalanceGE;

};

UCLASS(Transient)
class UFortWeaponModRuntimeData : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortRangedWeaponRecoil> PerBulletRecoil;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponFirstPersonData> OverrideFirstPersonData;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponFirstPersonData> CachedWeaponFirstPersonData;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CachedDefaultQuartzFireSound1P;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CachedDefaultQuartzFireSound3P;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CachedDefaultPrimaryFireSound1P;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> FireAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> FireDownsightsAnimation;

	UPROPERTY()
	TMap<FPrimaryAssetId, FFortTrackedModSubweaponList> SpawnedSubweapons;

	UPROPERTY()
	TMap<FGameplayTag, FFortTrackedModStaticMeshData> SpawnedStaticMeshes;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FActiveGameplayEffectHandle> ActiveRuntimeGEs;

	UPROPERTY(Transient)
	FWeaponModAnimData CachedAnimData;

	UPROPERTY()
	TMap<FPrimaryAssetId, FGameplayTagContainer> ModToAddedLooseTagMap;

};

