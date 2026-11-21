// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Timespan.h"
#include "Items/FortItemTypeEnum.h"
#include "SeasonPass/BattlePassTypes.h"
#include "BattlePassLandingPageButton.generated.h"

class UFortBangWrapper_NUI;
class UFortChallengeBundleScheduleDefinition;
class UFortItemDefinition;
class UMaterialInstance;
class UTexture2D;

UENUM(BlueprintType)
enum class EBattlePassLandingPageSpecialEntryType : uint8
{
	None = 0,
	Subscription = 1,
	CharacterCustomizer = 2,
	SpecialCharacter = 3,
	Weekly = 4,
	COUNT = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class FBattlePassLandingPageButtonDisplayBehavior : uint8
{
	None = 0,
	MainRewards = 1,
	BonusRewards = 2,
	WeeklyRewards = 3,
	QuestRewards = 4,
	Subscription = 5,
	Customization = 6,
};

USTRUCT(BlueprintType)
struct FBattlePassLandingPageButtonDisplayBehaviorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayBehaviorData")
	FBattlePassLandingPageButtonDisplayBehavior DisplayBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayBehaviorData")
	FTimespan BehaviorTimespan;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayBehaviorData")
	bool bIsDisplayActive;

};

USTRUCT(BlueprintType)
struct FBattlePassLandingPageButtonTexts
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonTexts", meta=(MultiLine="TRUE"))
	FText TileText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonTexts", meta=(MultiLine="TRUE"))
	FText LandingPageTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonTexts", meta=(MultiLine="TRUE"))
	FText LandingPageDescriptionText;

};

USTRUCT(BlueprintType)
struct FBattlePassLandingPageButtonDisplayDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayDetails")
	FBattlePassLandingPageButtonTexts ButtonTexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayDetails")
	bool bIsBPLocked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayDetails")
	FText MissingCosmeticNameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButtonDisplayDetails")
	FTimespan DelayTimespan;

};

USTRUCT(BlueprintType)
struct FBattlePassLandingPageEntryPreviewInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo")
	EBattlePassLandingPageSpecialEntryType SpecialEntryType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType == EBattlePassLandingPageSpecialEntryType::Subscription", EditConditionHides))
	TArray<EFortItemType> SubscriptionItemTypesToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType == EBattlePassLandingPageSpecialEntryType::SpecialCharacter", EditConditionHides))
	FGameplayTag SpecialCharacterVariantChannelToModify;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType == EBattlePassLandingPageSpecialEntryType::SpecialCharacter", EditConditionHides))
	FGameplayTag SpecialCharacterActiveVariantTag;

	UPROPERTY(EditInstanceOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType == EBattlePassLandingPageSpecialEntryType::Weekly", EditConditionHides))
	TMap<FString, TSoftObjectPtr<UMaterialInstance>> TemplateIdTileRenderMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType != EBattlePassLandingPageSpecialEntryType::Subscription && SpecialEntryType != EBattlePassLandingPageSpecialEntryType::CharacterCustomizer"))
	TArray<TSoftObjectPtr<UFortItemDefinition>> PreviewItems;

	UPROPERTY(EditInstanceOnly, Category="BattlePassLandingPageEntryPreviewInfo", meta=(EditCondition="SpecialEntryType == EBattlePassLandingPageSpecialEntryType::Weekly", EditConditionHides))
	bool bEnableDynamicWeeklyPreview;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageEntryPreviewInfo")
	float TransitionTime;

};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UBattlePassLandingPageButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FBattlePassLandingPageButtonDisplayDetails& GetBattlePassDisplayDetails() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayDetailsUpdated(const FBattlePassLandingPageButtonDisplayDetails& NewDisplayDetails);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowDisplayDetails();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSubscriptionOwnershipUpdated(const bool bOwnsSubsciption);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetTileImageMaterial(UMaterialInstance* Material);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSubscriptionTextureLoaded(UTexture2D* Texture);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButton", meta=(EditCondition="FeatureType == EBattlePassFeatures::None"))
	EBattlePassView SubPageType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButton", meta=(EditCondition="SubPageType == EBattlePassView::None"))
	EBattlePassFeatures FeatureType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLandingPageButton")
	FBattlePassLandingPageEntryPreviewInfo PreviewInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlock")
	bool bNeedsBattlePass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlock", meta=(EditCondition="DelayDaysSinceSeasonStart == 0"))
	TObjectPtr<UFortChallengeBundleScheduleDefinition> DelayQuestSchedule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlock", meta=(EditCondition="DelayQuestSchedule == nullptr"))
	int32 DelayDaysSinceSeasonStart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlock")
	TObjectPtr<UFortItemDefinition> RequiredItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper;

	UPROPERTY(EditAnywhere, Category="Telemetry")
	bool bUsesTelemetry;

	UPROPERTY(EditAnywhere, Category="Telemetry", meta=(EditCondition="bUsesTelemetry"))
	FIntPoint Telemetry_Size;

	UPROPERTY(EditAnywhere, Category="Telemetry", meta=(EditCondition="bUsesTelemetry"))
	FIntPoint Telemetry_Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Text")
	FBattlePassLandingPageButtonTexts DefaultTexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Text")
	FBattlePassLandingPageButtonTexts DelayedTexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Text", meta=(EditCondition="PreviewInfo.SpecialEntryType == EBattlePassLandingPageSpecialEntryType::Subscription"))
	FBattlePassLandingPageButtonTexts SubscribedTexts;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassLandingPageButton")
	FBattlePassLandingPageButtonDisplayBehaviorData DisplayBehaviorData;

};

