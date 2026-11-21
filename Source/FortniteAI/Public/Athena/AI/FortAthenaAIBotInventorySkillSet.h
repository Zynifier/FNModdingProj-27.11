// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortItemAndCount.h"
#include "FortAthenaAIBotInventorySkillSet.generated.h"

USTRUCT()
struct FBotEquipWeaponInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="BotEquipWeaponInfo", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="BotEquipWeaponInfo", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceEffectivenessWithThreat;

	UPROPERTY(EditDefaultsOnly, Category="BotEquipWeaponInfo", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceEffectivenessNoThreat;

};

USTRUCT()
struct FBotWeaponModScoreInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="BotWeaponModScoreInfo", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="BotWeaponModScoreInfo", meta=(AllowPrivateAccess="true"))
	FScalableFloat ModScore;

};

USTRUCT()
struct FDigestedBotEquipWeaponInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagQuery TagQuery;

	UPROPERTY(Transient)
	FScalableFloat DistanceEffectivenessWithThreat;

	UPROPERTY(Transient)
	FScalableFloat DistanceEffectivenessNoThreat;

};

USTRUCT()
struct FDigestedBotModScoreInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="DigestedBotModScoreInfo", meta=(AllowPrivateAccess="true"))
	float ModScore;

};

USTRUCT()
struct FWeaponAmmoCheat
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="WeaponAmmoCheat", meta=(AllowPrivateAccess="true"))
	FGameplayTag WeaponTag;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAmmoCheat", meta=(AllowPrivateAccess="true"))
	FScalableFloat HasInfiniteAmmo;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAmmoCheat", meta=(AllowPrivateAccess="true"))
	FScalableFloat CheckLoadedAmmoForInfiniteAmmo;

};

UCLASS()
class UFortAthenaAIBotInventoryDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float DefaultWeaponSelectionDistance;

	UPROPERTY(Transient)
	float DefaultWeaponSelectionDistanceDeviation;

	UPROPERTY(Transient)
	bool bHasInfiniteResources;

	UPROPERTY(Transient)
	bool bHasInfiniteAmmoForAllWeapons;

	UPROPERTY(Transient)
	FGameplayTagContainer InventorySlotPreference[6];

	UPROPERTY(Transient)
	TArray<FDigestedBotEquipWeaponInfo> EquipWeaponInfo;

	UPROPERTY(Transient)
	bool bShouldPrioritizeRangedWeaponWithoutTarget;

	UPROPERTY(Transient)
	FGameplayTagContainer InfiniteAmmoCheats;

	UPROPERTY(Transient)
	TArray<FItemAndCount> MaterialItems;

	UPROPERTY(Transient)
	float GiveMaterialsToBotFrequency;

	UPROPERTY(Transient)
	FGameplayTagContainer CheckLoadedAmmoForInfiniteAmmoCheats;

	UPROPERTY(Transient)
	float NoWeaponGiveWeaponAfterTime;

	UPROPERTY(Transient)
	float NoWeaponNoPlayerConeDistance;

	UPROPERTY(Transient)
	float NoWeaponNoPlayerConeFOV;

	UPROPERTY(Transient)
	FName NoWeaponLootTierGroup;

	UPROPERTY(Transient)
	FGameplayTagContainer IgnoredAsWeaponTags;

	UPROPERTY(Transient)
	float DefaultWeaponModScore;

	UPROPERTY(Transient)
	TArray<FDigestedBotModScoreInfo> WeaponModScoreInfo;

};

UCLASS()
class UFortAthenaAIBotInventorySkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefaultWeaponSelectionDistance;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefaultWeaponSelectionDistanceDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat HasInfiniteResources;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer InventorySlotPreference[6];

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FBotEquipWeaponInfo> EquipWeaponInfo;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldPrioritizeRangedWeaponWithoutTarget;

	UPROPERTY(EditDefaultsOnly, Category="Cheats")
	FScalableFloat HasInfiniteAmmoForAllWeapons;

	UPROPERTY(EditDefaultsOnly, Category="Cheats")
	TArray<FWeaponAmmoCheat> AmmoCheats;

	UPROPERTY(EditDefaultsOnly, Category="No Material Fallback")
	TArray<FItemAndCount> MaterialItems;

	UPROPERTY(EditDefaultsOnly, Category="No Material Fallback", meta=(AllowPrivateAccess="true"))
	FScalableFloat GiveMaterialsToBotFrequency;

	UPROPERTY(EditDefaultsOnly, Category="No Weapon Fallback", meta=(AllowPrivateAccess="true"))
	FScalableFloat NoWeaponGiveWeaponAfterTime;

	UPROPERTY(EditDefaultsOnly, Category="No Weapon Fallback", meta=(AllowPrivateAccess="true"))
	FScalableFloat NoWeaponNoPlayerConeDistance;

	UPROPERTY(EditDefaultsOnly, Category="No Weapon Fallback", meta=(AllowPrivateAccess="true"))
	FScalableFloat NoWeaponNoPlayerConeFOV;

	UPROPERTY(EditDefaultsOnly, Category="No Weapon Fallback", meta=(AllowPrivateAccess="true"))
	FName NoWeaponLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer IgnoredAsWeaponTags;

	UPROPERTY(EditDefaultsOnly, Category="Mods", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefaultWeaponModScore;

	UPROPERTY(EditDefaultsOnly, Category="Mods", meta=(AllowPrivateAccess="true"))
	TArray<FBotWeaponModScoreInfo> WeaponModScoreInfo;

};

