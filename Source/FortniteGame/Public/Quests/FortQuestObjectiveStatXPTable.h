// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "Items/FortAccoladeTypes.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortQuestObjectiveStatXPTable.generated.h"

class AFortPlayerController;
class UFortQuestItemDefinition;
class UTexture2D;

UENUM(BlueprintType)
enum class EFortSimulatedXPSize : uint8
{
	None = 0 UMETA(DisplayName="None"),
	VerySmall = 1 UMETA(DisplayName="Very Small"),
	Small = 2 UMETA(DisplayName="Small"),
	Medium = 3 UMETA(DisplayName="Medium"),
	Large = 4 UMETA(DisplayName="Large"),
	VeryLarge = 5 UMETA(DisplayName="Very Large"),
};

UENUM(BlueprintType)
enum class EFortXPPropagationRule : uint8
{
	Self = 0,
	Party = 1,
	Squad = 2,
};

USTRUCT(BlueprintType)
struct FFortQuestObjectiveStatXPTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveStatXPTableRow")
	EFortQuestObjectiveStatEvent Type;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer TargetTags;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer SourceTags;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer ContextTags;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer ExcludeTargetTags;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer ExcludeSourceTags;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FGameplayTagContainer ExcludeContextTags;

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DataTableImportOptional))
	FGameplayTagContainer ConditionStringGameplayTagsEditorCache_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortQuestObjectiveStatXPTableRow", meta=(DataTableImportOptional))
	TArray<FGameplayTag> ConditionStringGameplayTagsEditorCacheV2;
#endif

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FString Condition;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	int32 CountThreshhold;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	int32 MaxCount;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	FPrimaryAssetId AccoladePrimaryAssetId;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	bool bOnceOnly;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatXPTableRow")
	EFortXPPropagationRule XPPropagationRule;

	UPROPERTY(Transient, meta=(DataTableImportOptional))
	bool bIsCached;

};

USTRUCT(BlueprintType)
struct FXPEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	FName EventName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	FText SimulatedText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	FText SimulatedName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	EXPEventPriorityType Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	int32 EventXpValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	int32 TotalXpEarnedInMatch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	FPrimaryAssetId Accolade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	int32 RestedValuePortion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	int32 SeasonBoostValuePortion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	int32 RestedXPRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	TSoftObjectPtr<UTexture2D> AccoladeLargePreviewImageOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XPEventInfo")
	EFortSimulatedXPSize SimulatedXpSize;

};

USTRUCT()
struct FXpEventInfoOverrides
{
	GENERATED_BODY()

};

