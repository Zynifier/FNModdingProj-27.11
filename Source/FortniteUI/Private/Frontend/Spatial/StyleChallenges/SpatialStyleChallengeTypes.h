// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialStyleChallengeTypes.generated.h"

class UAnimationAsset;
class UAthenaCharacterItemDefinition;
class UFortQuestItemDefinition;
class UFortVariantTokenType;

UENUM(BlueprintType)
enum class ESpatialStyleCharacterUnlockPrerequisite : uint8
{
	BattlepassPurchase = 0,
	BattlepassLevel = 1,
};

USTRUCT(BlueprintType)
struct FAthenaStyleMissionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaStyleMissionData")
	TObjectPtr<UFortVariantTokenType> StyleDefinition;

	UPROPERTY(EditAnywhere, Category="AthenaStyleMissionData")
	TArray<TObjectPtr<UFortVariantTokenType>> OptionalAdditionalStyleDefinitions;

	UPROPERTY(EditAnywhere, Category="AthenaStyleMissionData")
	TObjectPtr<UFortQuestItemDefinition> Mission;

	UPROPERTY(EditAnywhere, Category="AthenaStyleMissionData")
	TObjectPtr<UAnimationAsset> OverrideIdleAnimation;

};

USTRUCT(BlueprintType)
struct FAthenaSpatialStyleCharacterData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSpatialStyleCharacterData")
	TObjectPtr<UAthenaCharacterItemDefinition> Character;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialStyleCharacterData")
	TArray<FAthenaStyleMissionData> Styles;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialStyleCharacterData")
	TArray<ESpatialStyleCharacterUnlockPrerequisite> CharacterPrerequisites;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialStyleCharacterData")
	TObjectPtr<UAnimationAsset> CharacterIdleAnimation;

};

