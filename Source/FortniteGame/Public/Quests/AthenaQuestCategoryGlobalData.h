// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "Quests/QuestProductGroup.h"
#include "AthenaQuestCategoryGlobalData.generated.h"

class UObject;
class UQuestCategoryData;

UCLASS()
class UAthenaQuestCategoryGlobalData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Product Data")
	FQuestProductData FallbackQuestProductData;

	UPROPERTY(EditAnywhere, Category="Categories")
	TObjectPtr<UQuestCategoryData> FallbackQuestCategory;

	UPROPERTY(EditAnywhere, Category="Categories")
	TArray<EFortQuestSubtype> ExcludedQuestSubTypes;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DefaultCategoryDisplayAsset;

	UPROPERTY(EditAnywhere, Category="Sorting")
	int32 HighPrioritySortThresholdHrs;

};

