// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Athena/ChallengeGiftBoxData.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "FortItemQuantityPair.h"
#include "Items/FortAccountItemDefinition.h"
#include "Quests/FortQuestTypes.h"
#include "Quests/LockedQuestData.h"
#include "FortChallengeBundleItemDefinition.generated.h"

class UAthenaCharacterItemDefinition;
class UFortChallengeBundleItemDefinition;
class UFortChallengeBundleItemDefinitionComponent;
class UFortChallengeSetStyleAsset;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestManager;
class UMaterial;
class UObject;
class UUserWidget;
enum class EBundleStyleColor : uint8;

UENUM(BlueprintType)
enum class EChallengeBundleQuestExpireType : uint8
{
	/** This quest is removed when the schedule is removed */
	WithSchedule = 0,
	/** This quest will be removed after a specific number of days */
	DaysFromEventStart = 1,
};

UENUM(BlueprintType)
enum class EChallengeBundleQuestUnlockType : uint8
{
	/** This quest is granted manually */
	Manually = 0,
	/** This quest is automatically granted when the bundle is granted */
	GrantWithBundle = 1,
	/** This quest will be automatically granted only if the user owns the battle pass */
	RequiresBattlePass = 2,
	/** This quest will be automatically granted after a specific number of days */
	DaysFromEventStart = 3,
	/** This quest is granted after completing X number of other challenges in the bundle */
	ChallengesCompletedToUnlock = 4,
	/** The quest is granted after the bundle has prestiged to level X */
	BundleLevelup = 5,
};

USTRUCT(BlueprintType)
struct FBundleGoalCardDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData", meta=(MultiLine="true"))
	FText HeaderText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData")
	FLinearColor HeaderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData")
	FText SubHeaderText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData")
	FLinearColor SubHeaderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> HeaderIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData")
	int32 MilestoneTier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BundleGoalCardDisplayData")
	int32 SortOrder;

};

USTRUCT()
struct FBundleEventDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BundleEventDisplayData")
	FBundleGoalCardDisplayData GoalCardDisplayData;

	UPROPERTY(EditAnywhere, Category="BundleEventDisplayData")
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FFortChallengeBundleLevelReward
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="FortChallengeBundleLevelReward")
	FAthenaRewardItemReference RewardItem;

	UPROPERTY(VisibleDefaultsOnly, Category="FortChallengeBundleLevelReward")
	int32 NumObjectivesNeeded;

};

USTRUCT()
struct FFortChallengeBundleLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="FortChallengeBundleLevel")
	TArray<FFortChallengeBundleLevelReward> BundleLevelRewardEntries;

};

USTRUCT(BlueprintType)
struct FFortChallengeBundleQuestEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleQuestEntry")
	TSoftObjectPtr<UFortQuestItemDefinition> QuestDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleQuestEntry")
	EChallengeBundleQuestUnlockType QuestUnlockType;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleQuestEntry")
	bool bIsPrerequisite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleQuestEntry", meta=(DisplayAfter="UnlockValue"))
	EChallengeBundleQuestExpireType QuestExpireType;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleQuestEntry")
	bool bAutoPinOnCreation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleQuestEntry", meta=(DisplayAfter="QuestUnlockType"))
	int32 UnlockValue;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleQuestEntry")
	FChallengeGiftBoxData RewardGiftBox;
#endif

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleQuestEntry")
	FFortItemQuantityPair MenuOverrideRewardPreview;

	UPROPERTY(VisibleDefaultsOnly, Category="FortChallengeBundleQuestEntry")
	int32 QuestChainLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleQuestEntry", meta=(DisplayAfter="QuestExpireType"))
	int32 ExpireValue;

};

USTRUCT()
struct FFortChallengeBundleRewards
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleRewards")
	int32 CompletionCount;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleRewards")
	bool bBundlePrestige;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleRewards")
	TArray<FAthenaRewardItemReference> Rewards;

};

USTRUCT()
struct FFortChallengeBundleSpecialOffer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleSpecialOffer")
	FString Storefront;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleSpecialOffer")
	FText RichText;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleSpecialOffer")
	TSoftObjectPtr<UMaterial> OfferImage;

};

USTRUCT()
struct FGlyphRewardInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GlyphRewardInfo")
	TObjectPtr<UFortChallengeBundleItemDefinition> BundleDef;

	UPROPERTY(EditDefaultsOnly, Category="GlyphRewardInfo")
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

};

UCLASS(Config=Game, PerObjectConfig, MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend"))
class UFortChallengeBundleItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	int32 GetBundleLevelForQuest(const UFortQuestItemDefinition* QuestDef) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	FString GetCalendarEventName() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	TArray<FAthenaRewardItemReference> GetCompletionRewards() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	const FFortChallengeSetStyle& GetDisplayStyle() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	FString GetEventName(bool bGetExpirationEvent = false) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	const FGameplayTag& GetGoalCardPinSeasonItemTag() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	FString GetHexCodeForStyleColor(EBundleStyleColor DesiredColor) const;

	UFUNCTION(Category="ChallengeBundle")
	const TSoftObjectPtr<UObject>& GetNotificationIconOverride() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	int32 GetNumQuests() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	int32 GetNumVisibleQuests() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	void GetQuests(const UFortQuestManager* QuestManager, const TArray<UFortQuestItem*>& GrantedQuests, TArray<UFortQuestItem*>& OwnedQuests, TArray<UFortQuestItemDefinition*>& UnownedQuests, bool bGetAllQuestsInChain = false) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	int32 GetRewardCompletionThreshold() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	int32 GetTotalNumberOfQuests() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	bool IsLinearChainQuest(const UFortQuestItemDefinition* InQuestDef, int32& ChainLength, int32& ChainPos) const;

private:
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition", meta=(DisplayName="Quest Visibility Data"))
	FQuestVisibilityData BundleVisiblityData;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition", meta=(TitleProperty="QuestDefinition"))
	TArray<FFortChallengeBundleQuestEntry> QuestInfos;

	UPROPERTY(EditDefaultsOnly, Category="FortChallengeBundleItemDefinition")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> SuppressedQuestDefs;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundle")
	FString CalendarEventTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundle")
	FString CalendarEventName;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TArray<FFortChallengeBundleRewards> BundleCompletionRewards;

	UPROPERTY(VisibleDefaultsOnly, Category="CoalesceChallengeBundleData")
	TArray<FFortChallengeBundleLevel> BundleLevelRewards;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TArray<FFortChallengeBundleSpecialOffer> SpecialOffers;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TObjectPtr<UFortChallengeSetStyleAsset> DisplayStyleAsset;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	FFortChallengeSetStyle CustomDisplayStyle;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	bool bPostDuplication;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	bool bPostDuplicationSave;
#endif

	UPROPERTY(VisibleDefaultsOnly, Category="CoalesceChallengeBundleData")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> CareerQuestBitShifts;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Modular Quests")
	TArray<TObjectPtr<UFortChallengeBundleItemDefinitionComponent>> BundleDefinitionComponents;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles"))
	FBundleGoalCardDisplayData GoalCardDisplayData;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles"))
	TArray<FBundleEventDisplayData> EventDisplayData;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles"))
	FGameplayTag GoalCardPinSeasonItemTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundle", meta=(DisplayAfter="CalendarEventName"))
	bool bUseSeasonEventForExpiration;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(DisplayName="Display As Loose Quests"))
	bool bSkipAddToGoalBundles;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles"))
	bool bIsGoalCardSelectable;

	UPROPERTY(EditAnywhere, Config, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles && bIsGoalCardSelectable"))
	bool bGoalCardInspectItemsAllowed;

	UPROPERTY(EditAnywhere, Config, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles && bIsGoalCardSelectable && bGoalCardInspectItemsAllowed"))
	bool bGoalCardInspectItemsGatherCategory;

	UPROPERTY(EditAnywhere, Config, Category="Goal Card", meta=(EditCondition="!bSkipAddToGoalBundles && bIsGoalCardSelectable && bGoalCardInspectItemsAllowed"))
	TArray<FFortItemQuantityPair> ManualInspectItemsList;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface", EditCondition="bIsGoalCardSelectable"))
	TSoftObjectPtr<UObject> GoalCardCustomMapBackground;

	UPROPERTY(EditAnywhere, Category="Goal Card", meta=(EditCondition="bIsGoalCardSelectable"))
	TSoftClassPtr<UUserWidget> GoalCardCustomMapWidget;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> NotificationIconOverride;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> QuestGiverWidgetIcon;

	UPROPERTY()
	FFortChallengeSetStyle DisplayStyle;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	FAthenaRewardItemReference OverrideRewardItem;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TObjectPtr<UAthenaCharacterItemDefinition> CharacterOverrideForRewardPreviews;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TSoftObjectPtr<UMaterial> BundleHidenImageMaterial;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	FText UniqueLockedMessage;

	UPROPERTY(EditAnywhere, Category="Locked Quests")
	FLockedQuestConfigData LockedQuestConfigData;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	bool bHideFromMapChallenges;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	uint8 bHideFromMapChallengeUntilBundleExists : 1;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	bool bHideWhenCompleted;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> HideUntilBundleCompleted;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	bool bHideRewardFromMapChallenges;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	bool bHideTimeRemaining;

	UPROPERTY(EditAnywhere, Category="FortChallengeBundleItemDefinition")
	bool bDeleteProgressTokenOnRemoval;

	UPROPERTY(EditDefaultsOnly, Category="FortChallengeBundleItemDefinition")
	bool bGetActiveQuestInChain;

	UPROPERTY(EditDefaultsOnly, Category="FortChallengeBundleItemDefinition")
	bool bUseQuestExpirationTimer;

};

