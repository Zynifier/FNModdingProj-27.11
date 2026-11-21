// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Misc/Guid.h"
#include "ChallengeBundles/FortChallengeBundleItemDefinition.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "QuestCategoryData.generated.h"

class UFortPlaylist;
class UObject;
class UUserWidget;

USTRUCT(BlueprintType)
struct FAutoGoalCardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AutoGoalCardData")
	FBundleGoalCardDisplayData DisplayData;

	UPROPERTY(EditDefaultsOnly, Category="AutoGoalCardData")
	EFortQuestType QuestType;

	UPROPERTY(EditDefaultsOnly, Category="AutoGoalCardData")
	EFortQuestSubtype QuestSubtype;

	UPROPERTY(EditAnywhere, Category="AutoGoalCardData")
	FGameplayTag RequiredQuestTag;

	UPROPERTY(EditAnywhere, Category="AutoGoalCardData")
	FGameplayTag HeaderTag;

};

USTRUCT(BlueprintType)
struct FCustomMessageQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CustomMessageQuestData")
	FText CustomMessage;

	UPROPERTY(EditAnywhere, Category="CustomMessageQuestData")
	FGameplayTag HeaderTag;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FQuestCategoryButtonOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> BackgroundMaterialOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> ExtensionImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(InlineEditConditionToggle))
	bool bOverrideHeaderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(EditCondition="bOverrideHeaderColor"))
	FLinearColor HeaderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(InlineEditConditionToggle))
	bool bOverrideTimerColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategoryButtonOverrides", meta=(EditCondition="bOverrideTimerColor"))
	FLinearColor TimerColor;

};

USTRUCT(BlueprintType)
struct FQuestCategoryHeaderData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestCategoryHeaderData")
	FText HeaderName;

	UPROPERTY(EditAnywhere, Category="QuestCategoryHeaderData")
	FGameplayTag HeaderTag;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer IncludedGameModeTags;

	UPROPERTY(EditAnywhere, Category="QuestCategoryHeaderData")
	FGameplayTagContainer DisabledGameModeTags;

	UPROPERTY(EditAnywhere, Category="QuestCategoryHeaderData")
	int32 HeaderSortOrder;

};

UCLASS(Config=Game, PerObjectConfig)
class UQuestCategoryData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Behavior")
	bool bCategoryEnabled;

	UPROPERTY(EditAnywhere, Category="Display")
	bool bSuppressBangs;

	UPROPERTY(EditAnywhere, Category="Display")
	bool bSuppressBangsIfAllAutoGoalsAreAccomplished;

	UPROPERTY(EditAnywhere, Category="Quests")
	bool bIncludeAllQuests;

	UPROPERTY(EditAnywhere, Category="Map")
	bool bDisplayMap;

	UPROPERTY(EditAnywhere, Config, Category="Category Button")
	bool bAlwaysDisplay;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DisplayAsset;

	UPROPERTY(EditAnywhere, Category="Display")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="Display")
	FText DisplaySubText;

	UPROPERTY(EditAnywhere, Category="Headers|Default")
	FText DefaultHeaderName;

	UPROPERTY(EditAnywhere, Category="Headers|Default")
	int32 DefaultHeaderSortOrder;

	UPROPERTY(EditAnywhere, Category="Headers|Additional")
	TArray<FQuestCategoryHeaderData> AdditionalHeaders;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(EditCondition="!bIncludeAllQuests"))
	FGameplayTagContainer IncludeTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer ExcludeTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer IncludedGameModeTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer DisabledGameModeTags;

	UPROPERTY(EditAnywhere, Category="Discovery")
	TSoftObjectPtr<UFortPlaylist> DiscoveryPlaylist;

	UPROPERTY(EditAnywhere, Category="Map", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface", EditCondition="bDisplayMap"))
	TSoftObjectPtr<UObject> CustomMapBackground;

	UPROPERTY(EditAnywhere, Category="Map", meta=(EditCondition="bDisplayMap"))
	TSoftClassPtr<UUserWidget> CustomMapWidget;

	UPROPERTY(EditAnywhere, Config, Category="Category Button")
	FString RequiredProfileItemTemplateId;

	UPROPERTY(EditAnywhere, Category="Category Button")
	FText CustomTimeRemaining;

	UPROPERTY(EditAnywhere, Category="Category Button")
	int32 SortOrder;

	UPROPERTY(EditAnywhere, Category="Category Button")
	FQuestCategoryButtonOverrides ButtonOverrides;

	UPROPERTY(EditAnywhere, Config, Category="Category Button")
	bool bDisplayProgressBar;

	UPROPERTY(EditAnywhere, Config, Category="Category Button")
	bool bCountGoals;

	UPROPERTY(EditAnywhere, Config, Category="Category Button", meta=(EditCondition="bCountGoals"))
	bool bCountObjectives;

	UPROPERTY(EditAnywhere, Config, Category="Category Button")
	bool bCountStages;

	UPROPERTY(EditAnywhere, Category="Additional Widgets|All Quests Complete")
	bool bCanShowAllQuestsCompleted;

	UPROPERTY(EditAnywhere, Category="Additional Widgets|Party Up")
	bool bCanShowPartyUpWidget;

	UPROPERTY(EditAnywhere, Category="Auto Goal Cards")
	TArray<FAutoGoalCardData> AutoGoalCards;

	UPROPERTY(EditAnywhere, Category="Additional Widgets|All Quests Complete", meta=(EditCondition="bCanShowAllQuestsCompleted"))
	FGameplayTag AllQuestsCompleteHeaderTag;

	UPROPERTY(EditAnywhere, Category="Additional Widgets|Party Up", meta=(EditCondition="bCanShowPartyUpWidget"))
	FGameplayTag PartyUpHeaderTag;

	UPROPERTY(EditAnywhere, Category="Additional Widgets|Custom")
	TArray<FCustomMessageQuestData> CustomMessageData;

private:
	UPROPERTY(VisibleAnywhere, Category="Data")
	FGuid CategoryGuid;

};

