// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortItemQuantityPair.h"
#include "FortCalendarEventInventoryTransformData.generated.h"

class UFortItemDefinition;
class UFortPersistentResourceItemDefinition;
class UFortQuestItemDefinition;

USTRUCT(BlueprintType)
struct FRecipeDataTableRowHandleQuantityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RecipeDataTableRowHandleQuantityData")
	FDataTableRowHandle DataTableRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RecipeDataTableRowHandleQuantityData")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RecipeDataTableRowHandleQuantityData")
	bool ConvertRemainderUp;

};

USTRUCT()
struct FFortCalendarEventInventoryTransformData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCalendarEventInventoryTransformData", meta=(DataTableImportOptional))
	FName CalendarChannelName;

	UPROPERTY(EditAnywhere, Category="FortCalendarEventInventoryTransformData")
	FName CalendarEventName;

	UPROPERTY(EditAnywhere, Category="FortCalendarEventInventoryTransformData")
	TArray<FName> AllowedProfileTypes;

	UPROPERTY(EditAnywhere, Category="Prerequisites", meta=(DataTableImportOptional))
	FGameplayTagContainer PrerequisiteHomebaseProperties;

	UPROPERTY(EditDefaultsOnly, Category="Prerequisites", meta=(DataTableImportOptional))
	TSoftObjectPtr<UFortQuestItemDefinition> PrerequisiteQuest;

	UPROPERTY(EditAnywhere, Category="Prerequisites", meta=(DataTableImportOptional))
	FDataTableRowHandle PrerequisiteObjective;

	UPROPERTY(EditAnywhere, Category="Prerequisites", meta=(DataTableImportOptional))
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> PrerequisiteIncompleteOrUngrantedQuests;

	UPROPERTY(EditAnywhere, Category="Prerequisites", meta=(DataTableImportOptional))
	TArray<TSoftObjectPtr<UFortItemDefinition>> PrerequisiteUnownedItems;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ItemsToGrantString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ConversionRecipesToRunOnEventStartString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ConversionRecipesToRunAfterEventString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ItemsToRemoveAfterEventString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString PrerequisiteHomebasePropertyString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString PrerequisiteObjectiveString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString PrerequisiteIncompleteOrUngrantedQuestsString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString PrerequisiteUnownedItemsString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ItemsToGrantByTemplateString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString ItemsToRemoveAfterEventByTemplateString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString QuestsOnlyActiveDuringEventString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString EventCurrencyString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Import Strings")
	FString MetadataString;
#endif

	UPROPERTY(VisibleAnywhere, Category="Quests only active during event", meta=(DataTableImportOptional))
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestsOnlyActiveDuringEvent;

	UPROPERTY(VisibleAnywhere, Category="Items to grant", meta=(DataTableImportOptional))
	TArray<FFortItemQuantityPair> ItemsToGrant;

	UPROPERTY(EditAnywhere, Category="Items to grant", meta=(DataTableImportOptional))
	TArray<FFortHiddenRewardQuantityPair> ItemsToGrantByTemplate;

	UPROPERTY(EditAnywhere, Category="Conversion", meta=(DataTableImportOptional))
	TArray<FRecipeDataTableRowHandleQuantityData> ConversionRecipesToRunOnEventStart;

	UPROPERTY(EditAnywhere, Category="Conversion", meta=(DataTableImportOptional))
	TArray<FRecipeDataTableRowHandleQuantityData> ConversionRecipesToRunAfterEvent;

	UPROPERTY(VisibleAnywhere, Category="Items to remove after event", meta=(DataTableImportOptional))
	TArray<FFortItemQuantityPair> ItemsToRemoveAfterEvent;

	UPROPERTY(EditAnywhere, Category="Items to remove after event", meta=(DataTableImportOptional))
	TArray<FFortHiddenRewardQuantityPair> ItemsToRemoveAfterEventByTemplate;

	UPROPERTY(EditDefaultsOnly, Category="Currency", meta=(DataTableImportOptional))
	TSoftObjectPtr<UFortPersistentResourceItemDefinition> EventCurrency;

	UPROPERTY(EditDefaultsOnly, Category="Currency", meta=(DataTableImportOptional))
	float EventCurrencyConversionFactor;

	UPROPERTY(EditDefaultsOnly, Category="Metadata", meta=(DataTableImportOptional))
	TMap<FString, FString> Metadata;

};

USTRUCT()
struct FRecipeData
{
	GENERATED_BODY()

};

