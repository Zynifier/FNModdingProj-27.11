// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortCharacterCustomizationManagerComponent.generated.h"

class UAnimInstance;
class UCustomCharacterPart;
class UFortAnimInstance;
class UFortFootstepAudioBank;
class UFortLocomotionAnimAsset;
class UFortWeaponAnimSet;

USTRUCT()
struct FFortCharacterCustomization
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterPartOverrides;

	UPROPERTY()
	TSubclassOf<UFortAnimInstance> AnimBPClassOverride;

	UPROPERTY()
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSetOverride;

	UPROPERTY()
	TObjectPtr<UFortLocomotionAnimAsset> LocomotionAnimAssetOverride;

	UPROPERTY()
	TArray<TSubclassOf<UAnimInstance>> AnimLayersOverride;

	UPROPERTY()
	TObjectPtr<UFortFootstepAudioBank> FootstepBankOverride;

};

USTRUCT(BlueprintType)
struct FFortCharacterCustomizationHandle
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 Handle;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortCharacterCustomizationManagerComponent : public UFortPlayerStateComponent
{
	GENERATED_BODY()

};

