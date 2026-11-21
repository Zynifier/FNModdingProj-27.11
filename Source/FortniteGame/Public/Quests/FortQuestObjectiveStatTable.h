// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortQuestObjectiveStatTable.generated.h"

UENUM()
enum class EInlineObjectiveStatTagCheckEntryType : uint8
{
	Target = 0,
	Source = 1,
	Context = 2,
};

USTRUCT()
struct FInlineObjectiveStatTagCheckEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="InlineObjectiveStatTagCheckEntry")
	FGameplayTag Tag;

	UPROPERTY(VisibleAnywhere, Category="InlineObjectiveStatTagCheckEntry")
	EInlineObjectiveStatTagCheckEntryType Type;

	UPROPERTY(VisibleAnywhere, Category="InlineObjectiveStatTagCheckEntry")
	uint8 Require : 1;

};

USTRUCT(BlueprintType)
struct FFortQuestObjectiveStat
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortQuestObjectiveStat")
	TArray<FInlineObjectiveStatTagCheckEntry> TagConditions;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FString Condition;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	TArray<FString> TemplateIds;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	bool bCollectPotentialLocationTags;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer TargetTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer SourceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer ContextTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer ExcludeTargetTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer ExcludeSourceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat")
	FGameplayTagContainer ExcludeContextTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DataTableImportOptional))
	FGameplayTagContainer ConditionStringGameplayTagsEditorCache_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortQuestObjectiveStat", meta=(DataTableImportOptional))
	TArray<FGameplayTag> ConditionStringGameplayTagsEditorCacheV2;
#endif

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStat", meta=(DisplayPriority="1"))
	EFortQuestObjectiveStatEvent Type;

	UPROPERTY(Transient)
	uint8 bIsCached : 1;

	UPROPERTY()
	uint8 bHasInclusiveTargetTags : 1;

	UPROPERTY()
	uint8 bHasInclusiveSourceTags : 1;

	UPROPERTY()
	uint8 bHasInclusiveContextTags : 1;

};

USTRUCT(BlueprintType)
struct FFortQuestObjectiveStatTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveStatTableRow")
	EFortQuestObjectiveStatEvent Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveStatTableRow", meta=(DataTableImportOptional, DisplayName="Target Tags"))
	FGameplayTagContainer TargetTagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveStatTableRow", meta=(DataTableImportOptional, DisplayName="Source Tags"))
	FGameplayTagContainer SourceTagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveStatTableRow", meta=(DataTableImportOptional, DisplayName="Context Tags"))
	FGameplayTagContainer ContextTagContainer;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatTableRow")
	FString Condition;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatTableRow")
	FString TemplateId;

	UPROPERTY(EditAnywhere, Category="FortQuestObjectiveStatTableRow", meta=(DataTableImportOptional))
	TArray<FString> AlternateTemplateIds;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FString TargetTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FString SourceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FString ContextTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DataTableImportOptional))
	FGameplayTagContainer ConditionStringGameplayTagsEditorCache_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortQuestObjectiveStatTableRow", meta=(DataTableImportOptional))
	TArray<FGameplayTag> ConditionStringGameplayTagsEditorCacheV2;
#endif

	UPROPERTY(Transient, meta=(DataTableImportOptional))
	bool bIsCached;

};

