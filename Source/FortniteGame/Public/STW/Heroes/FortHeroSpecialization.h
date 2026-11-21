// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortTypes.h"
#include "FortHeroSpecialization.generated.h"

class UCustomCharacterPart;
class UFortAbilityKit;

UENUM(BlueprintType)
enum class EFortSupportBonusType : uint8
{
	Normal = 0,
	Tactical = 1,
	Max_None = 2,
};

USTRUCT(BlueprintType)
struct FHeroSpecializationAttributeRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	float MinimumValue;

};

USTRUCT(BlueprintType)
struct FFortSpecializationSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities", meta=(AssetBundles="ItemDetails"))
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	TSoftObjectPtr<UFortAbilityKit> RemovedAbilityKit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	TArray<FHeroSpecializationAttributeRequirement> AttributeRequirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	int32 MinimumHeroLevel;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AlterationCosmetic", "AlterationGameplay"))
class UFortHeroSpecialization : public UPrimaryDataAsset
{
	GENERATED_BODY()

	friend class UAthenaCharacterItemDefinition;

public:
	UFUNCTION(BlueprintPure, Category="CharacterParts")
	const TArray<TSoftObjectPtr<UCustomCharacterPart>>& GetCharacterPartPtrs() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="SpecializationSlots", meta=(AssetBundles="ItemDetails"))
	TArray<FFortSpecializationSlot> SpecializationSlots;

	UPROPERTY(EditDefaultsOnly, Category="CharacterParts", meta=(AssetBundles="Server,AvatarDisplay"))
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterParts;

	UPROPERTY(EditAnywhere, Category="AlterationDefinition")
	TEnumAsByte<EFortAlteration::Type> AlterationType;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	TArray<FHeroSpecializationAttributeRequirement> AttributeRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditDefaultsOnly, Category="CharacterParts")
	uint8 bForceShowHeadAccessory : 1;

	UPROPERTY(EditDefaultsOnly, Category="CharacterParts")
	uint8 bForceShowBackpack : 1;

	UPROPERTY(VisibleAnywhere, Category="Display", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDisplayGender"))
	FSlateBrush CardIconBrush[3];

};

