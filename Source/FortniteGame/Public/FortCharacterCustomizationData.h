// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortCharacterCustomizationData.generated.h"

class UAnimInstance;
class UCustomCharacterPart;
class UFortAnimInstance;
class UFortFootstepAudioBank;
class UFortLocomotionAnimAsset;
class UFortWeaponAnimSet;

UCLASS(BlueprintType)
class UFortCharacterCustomizationData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Model", meta=(AssetBundles="Equipped"))
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterPartOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Animation", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UFortAnimInstance> AnimBPOverride;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Animation", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortWeaponAnimSet> WeaponAnimSetOverride;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Animation", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortLocomotionAnimAsset> LocomotionAnimAssetOverride;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Animation", meta=(AssetBundles="Equipped"))
	TArray<TSoftClassPtr<UAnimInstance>> AnimLayersOverride;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | Sound", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortFootstepAudioBank> FootstepBankOverride;

	UPROPERTY(EditDefaultsOnly, Category="Customization Data | General")
	int32 Priority;

};

