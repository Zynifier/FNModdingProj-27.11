// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaCharmItemDefinition.generated.h"

class ACustomCosmeticCharmModifier;
class AFortPlayerCharm;
class UAnimInstance;
class USkeletalMesh;
class USoundBase;

USTRUCT(BlueprintType)
struct FCharmSoundAssetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, Category="CharmSoundAssetEntry")
	FName Desc;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaCharmItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Visual")
	TSubclassOf<AFortPlayerCharm> GetCharmPrefabClass() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftClassPtr<UAnimInstance> GetOverrideAnimSetPtr() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftClassPtr<UAnimInstance> GetOverrideAnimSetPtrForCharmSlot(const int32 CharmSlotIn) const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftObjectPtr<USkeletalMesh> GetOverrideSkelMeshPtr() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftClassPtr<UAnimInstance> GetOverrideWeaponAnimSetPtr() const;

	UPROPERTY(EditAnywhere, Category="Athena", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<ACustomCosmeticCharmModifier> CharmModifierBlueprint;

private:
	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<AFortPlayerCharm> CharmPrefabClass;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UAnimInstance> WeaponAnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TArray<FCharmSoundAssetEntry> CharmSounds;

};

