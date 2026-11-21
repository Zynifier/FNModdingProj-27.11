// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortRarityEnum.h"
#include "FortWeaponEnums.h"
#include "SFortMakeDesignWeaponAssetForm.generated.h"

class AFortProjectileBase;
class AFortWeapon;
class UFortAlterationItemDefinition;
class UFortGameplayAbility;
class UFortWorldItemDefinition;
class USkeletalMesh;
class USoundBase;
class UTexture2D;

UENUM()
enum class EMeleeWeaponCategory : uint8
{
	None = 0,
	Blunt = 1,
	Edged = 2,
	Piercing = 3,
};

UENUM()
enum class ERangedWeaponCategory : uint8
{
	None = 0,
	Assault = 1,
	Explosive = 2,
	Pistol = 3,
	Shotgun = 4,
	Sniper = 5,
	SMG = 6,
};

UENUM()
enum class EWeaponRange : uint8
{
	None = 0,
	Melee = 1,
	Ranged = 2,
};

USTRUCT()
struct FWeaponItemDefinitionDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Main", meta=(DisplayName="Weapon Type (Melee or Ranged?)"))
	EWeaponRange WeaponRange;

	UPROPERTY(EditAnywhere, Category="Main")
	ERangedWeaponCategory RangedWeaponCategory;

	UPROPERTY(EditAnywhere, Category="Main")
	EMeleeWeaponCategory MeleeWeaponCategory;

	UPROPERTY(EditAnywhere, Category="Main")
	FName AssetName;

	UPROPERTY(EditAnywhere, Category="Main")
	EFortRarity StartingRarity;

	UPROPERTY(EditAnywhere, Category="Main")
	EFortRarity EndingRarity;

	UPROPERTY(EditAnywhere, Category="Main")
	bool bCreateCrystalWeapons;

	UPROPERTY(EditAnywhere, Category="Main")
	bool bSchematicObeysInventorySizeLimits;

	UPROPERTY(EditAnywhere, Category="Main")
	bool bGenerateSacrificeRecipes;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSubclassOf<AFortWeapon> WeaponActorClass;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSoftObjectPtr<USkeletalMesh> WeaponMeshOverride;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSoftObjectPtr<UFortAlterationItemDefinition> BaseAlteration;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSoftObjectPtr<UFortAlterationItemDefinition> BaseCosmeticAlteration;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSoftObjectPtr<UFortWorldItemDefinition> AmmoData;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TEnumAsByte<EFortWeaponTriggerType::Type> TriggerType;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TEnumAsByte<EFortWeaponTriggerType::Type> SecondaryTriggerType;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	float DisassembleDurabilityDegradeMinLootPercent;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	float DisassembleDurabilityDegradeMaxLootPercent;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> PrimaryFireAbility;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> SecondaryFireAbility;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> ReloadAbility;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray<TSoftClassPtr<UFortGameplayAbility>> EquippedAbilities;

	UPROPERTY(EditAnywhere, Category="Ranged Weapon Data")
	TSoftClassPtr<AFortProjectileBase> ProjectileTemplate;

	UPROPERTY(EditAnywhere, Category="Ranged Weapon Data")
	bool PiercesPawns;

	UPROPERTY(EditAnywhere, Category="Display")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="Display")
	FText Description;

	UPROPERTY(EditAnywhere, Category="Display")
	FText SearchTags;

	UPROPERTY(EditAnywhere, Category="Display")
	TObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditAnywhere, Category="Display")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(EditAnywhere, Category="Display")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditAnywhere, Category="Display")
	float MiniMapViewableDistance;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TSoftObjectPtr<USoundBase> PickupSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TSoftObjectPtr<USoundBase> DropSound;

	UPROPERTY(EditAnywhere, Category="Owned Tags")
	FGameplayTagContainer WeaponTags;

	UPROPERTY(EditAnywhere, Category="Owned Tags")
	FGameplayTagContainer SchematicTags;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bNeverPersisted;

};

