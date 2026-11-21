// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortGender.h"
#include "FortRarityEnum.h"
#include "MakeDesignAsset/SFortMakeDesignAssetUtility.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "SFortMakeDesignHeroAssetForm.generated.h"

class AFortPlayerPawn;
class UCustomCharacterPart;
class UFortFeedbackBank;
class UFrontendAnimInstance;
class UTexture2D;

UENUM()
enum class EHeroStatProfile : uint8
{
	Balanced = 0,
	Health = 1,
	Ability = 2,
	Shields = 3,
	MAX_None = 4,
};

UENUM()
enum class EHeroTypeNames : uint8
{
	HTN_Soldier = 0 UMETA(DisplayName="Soldier"),
	HTN_Constructor = 1 UMETA(DisplayName="Constructor"),
	HTN_Outlander = 2 UMETA(DisplayName="Outlander"),
	HTN_Ninja = 3 UMETA(DisplayName="Ninja"),
	HTN_MAX = 4 UMETA(DisplayName="None"),
};

USTRUCT()
struct FHeroSpecializationDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Main")
	FName AssetName;

	UPROPERTY(EditAnywhere, Category="Main")
	EFortRarity StartingRarity;

	UPROPERTY(EditAnywhere, Category="Main")
	EFortRarity EndingRarity;

	UPROPERTY(EditAnywhere, Category="Main")
	bool EventUnique;

	UPROPERTY(EditAnywhere, Category="Type")
	EHeroTypeNames HeroClass;

	UPROPERTY(EditAnywhere, Category="Type")
	EHeroStatProfile StatProfile;

	UPROPERTY(EditAnywhere, Category="Type")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, Category="Display")
	FName DisplayName;

	UPROPERTY(EditAnywhere, Category="Display")
	FName Description;

	UPROPERTY(EditAnywhere, Category="Specialization Slots")
	TArray<FFortSpecializationSlot> TierOneSlots;

	UPROPERTY(EditAnywhere, Category="Specialization Slots")
	TArray<FFortSpecializationSlot> TierTwoSlots;

	UPROPERTY(EditAnywhere, Category="Specialization Slots")
	TArray<FFortSpecializationSlot> TierThreeSlots;

	UPROPERTY(EditAnywhere, Category="Specialization Slots")
	TArray<FFortSpecializationSlot> TierFourSlots;

	UPROPERTY(EditAnywhere, Category="Character Parts")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterPartsTierOne;

	UPROPERTY(EditAnywhere, Category="Character Parts")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterPartsTierTwo;

	UPROPERTY(EditAnywhere, Category="Character Parts")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterPartsTierThree;

	UPROPERTY(EditAnywhere, Category="Owned Tags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftObjectPtr<UFortFeedbackBank> MaleOverrideFeedback;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftObjectPtr<UFortFeedbackBank> FemaleOverrideFeedback;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FCurveAssetForm LevelToXpHandle;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FCurveAssetForm LevelToSacrificeXpHandle;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FDataAssetForm SacrificeRecipe;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FDataAssetForm TransmogSacrificeRow;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TArray<FDataAssetForm> ConversionRecipes;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FCurveAssetForm RatingLookup;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FDataAssetForm LegacyStatHandle;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FGameplayTagContainer RequiredGPTags;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftClassPtr<AFortPlayerPawn> OverridePawnClass;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftClassPtr<UFrontendAnimInstance> FrontendAnimClass;

	UPROPERTY()
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bNeverPersisted;

};

