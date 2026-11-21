// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "AthenaChallengeListEntry.generated.h"

class IAthenaChallengeListEntryContextInterface;
class UAthenaChallengeProgressBar;
class UAthenaChallengeRewardDisplay;
class UButton;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortLazyImage;
class UFortStoreFrontOfferDetailsWidgetBase;
class UFortStoreFrontOfferInfo;
class UImage;
class UWidgetAnimation;
enum class EChallengeListSection : uint8;

UENUM(BlueprintType)
enum class EChallengeListEntryType : uint8
{
	DisabledHeader = 0,
	GoalCard = 1,
	Header = 2,
	Normal = 3,
	PartyUp = 4,
	LockedQuest = 5,
	AllQuestsComplete = 6,
	CustomMessage = 7,
	Count = 8 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EChallengeListSection : uint8
{
	SpecialOffers = 0,
	CompletionRewards = 1,
	AllChallenges = 2,
	FreeChallenges = 3,
	PaidChallenges = 4,
	Objectives = 5,
};

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntryBase : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Challenge Info Set"))
	void BP_OnChallengeInfoSet(bool bDisabled);

	UFUNCTION(BlueprintImplementableEvent)
	void EndHighlight();

	UFUNCTION(BlueprintImplementableEvent)
	void StartHighlight();

protected:
	UPROPERTY(Transient)
	TScriptInterface<IAthenaChallengeListEntryContextInterface> EntryContext;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_Challenge : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Is Tracked Challenge Changed"))
	void BP_HandleIsTrackedChallengeChanged(bool bIsTrackedChallenge);

	UFUNCTION(BlueprintPure)
	int32 GetChallengeWeight() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeInfoSet(bool bIsComplete, bool bIsLocked, bool bIsGroupChallenge, bool bCompact, bool HideRewards);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartyAssistEnabledChanged(bool bIsPartyAssistEnabled);

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListEntry_Challenge")
	bool bHideProgressBar;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ChallengeDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeProgressBar> ChallengeProgress_ObjectivesCompleted;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_CompletionReward : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardInfoSet(bool bIsCompleted, const FFortChallengeSetStyle& DisplayStyle);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewardDisplay> Reward_CompletionReward;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeProgressBar> ChallengeProgress_ObjectivesCompleted;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_DetailedChallenge : public UAthenaChallengeListEntry_Challenge
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCloseChallengeOptionsInputAction(bool& bPassThrough);

	UFUNCTION()
	void HandleUpperAreaClicked();

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeListEntry_DetailedChallenge", meta=(AllowPrivateAccess="TRUE"))
	bool bHasAnyOptionsAvailable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeListEntry_DetailedChallenge", meta=(AllowPrivateAccess="TRUE"))
	bool bIsDisplayingChallengeActions;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListEntry_DetailedChallenge", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListEntry_DetailedChallenge", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseChallengeOptionsAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeListEntry_DetailedChallenge", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_ShowChallengeOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> SimpleButton_TopClickArea;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewardDisplay> Reward_QuestReward;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PartyAssist;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ReplaceChallenge;

	UPROPERTY(Export, meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ActionInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_Header : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSectionTypeSet(EChallengeListSection SectionType);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SectionTitle;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_StoreOffer : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOfferSet();

	UPROPERTY(EditAnywhere, Category="StoreOffer")
	TSoftClassPtr<UFortStoreFrontOfferDetailsWidgetBase> OfferDetailsWidgetClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OfferInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> SimpleButton_ClickArea;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_SpecialOffer;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeRewardDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeRewardDisplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaChallengeRewardDisplayEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Rewards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CompletionIcon;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeRewardDisplayEntry : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeRewardDisplayEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_RewardIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardQuantity;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeTreeEntry_ChallengeSet : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeSetEstablished(const FFortChallengeSetStyle& DisplayStyle);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengeSetName;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengeSetContext;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PercentComplete;

};

