// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "SpatialCustomizationRoomData.generated.h"

class UAthenaConfirmationWindow;
class UAthenaCosmeticItemDefinition;
class UAthenaRewardEventGraph;
class UFortChallengeBundleItemDefinition;

UENUM(BlueprintType)
enum class ESpatialCustomizationCategoryState : uint8
{
	LockedByBattlePass = 0,
	LockedByChallenge = 1,
	LockedByChallengeCompletion = 2,
	UnlockAvailable = 3,
	UnlockUsed = 4,
	Max_NONE = 5 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FSpatialCustomizationCategoryStateData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpatialCustomizationCategoryStateData")
	ESpatialCustomizationCategoryState State;

	UPROPERTY(EditAnywhere, Category="SpatialCustomizationCategoryStateData")
	FLinearColor Color;

	UPROPERTY(EditAnywhere, Category="SpatialCustomizationCategoryStateData")
	FText CategorySelectionHeaderText;

};

UCLASS(BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationRoomData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TObjectPtr<UAthenaCosmeticItemDefinition> CustomizationCosmetic;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TObjectPtr<UAthenaRewardEventGraph> CustomizationRoomGraph;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TObjectPtr<UFortChallengeBundleItemDefinition> CustomizationChallengeBundle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationWindowClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TArray<FSpatialCustomizationCategoryStateData> CategoryStates;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText FinalizeConfirmationTitle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText FinalizeConfirmationDescription;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText UnlockAvailableText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText UnlockUsedText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText LockedByBattlePassText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText LockedByChallengeFormat;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText LockedByChallengeCompletionText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FText LockedByChallengeBundleCompletionFormat;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	bool bUseNullColorOption;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	FLinearColor NullColor;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoomData")
	TArray<FLinearColor> Swatches;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialCustomizationRoomData")
	bool bShowSelectedChoiceName;

};

