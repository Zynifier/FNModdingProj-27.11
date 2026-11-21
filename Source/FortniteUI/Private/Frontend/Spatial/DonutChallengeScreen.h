// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Frontend/Spatial/SpatialScreen.h"
#include "DonutChallengeScreen.generated.h"

class UAthenaChallengeCountdownDisplay;
class UAthenaChallengeProgressBar;
class UAthenaSeasonItemDefinition;
class UCommonButtonLegacy;
class UCommonHierarchicalScrollBox;
class UCommonTextBlock;
class UDonutChallengeEntry;
class UDonutChallengeEntryHeader;
class UDynamicEntryBox;
class UFortChallengeBundleItemDefinition;
class UFortGameStateComponent_EventLevel;
class UFortLazyImage;
class UImage;
class UUserWidget;

UCLASS(meta=(DisableNativeTick))
class UDonutChallengeEntry : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BPHasRewardTexture(bool InHasReward);

	UFUNCTION(BlueprintImplementableEvent)
	void BPIsCompleted(bool InCompletion);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_Reward;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Completed;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeProgressBar> ProgressBar_Challenge;

};

UCLASS(meta=(DisableNativeTick))
class UDonutChallengeEntryHeader : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BPUpdateTitle(int32 InWeek);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeEntryHeader", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeCountdownDisplay> Timer_UnlockTimer;

};

UCLASS(meta=(DisableNativeTick))
class UDonutChallengeScreen : public UAthenaSpatialScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ScrollToEndOfChallenges();

	UFUNCTION(BlueprintCallable)
	void SetEntryFocus();

	UFUNCTION(BlueprintCallable)
	void SetStyledCursorEnabled(bool bEnableStyledCursor);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowSkinUnlockMessage(bool bShowMessage, int32 InChallengeNum);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBPOwnedStateVisuals(bool bInOwnsBattlePass);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventGameStateComponent;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonData;

	UPROPERTY(EditAnywhere, Category="DonutChallengeScreen")
	TSoftClassPtr<UUserWidget> CustomMouseCursorWidget;

	UPROPERTY(EditAnywhere, Category="DonutChallengeScreen")
	TSubclassOf<UDonutChallengeEntryHeader> HeaderEntryClass;

	UPROPERTY(EditAnywhere, Category="DonutChallengeScreen")
	TSubclassOf<UDonutChallengeEntry> EntryClass;

	UPROPERTY(EditAnywhere, Category="DonutChallengeScreen")
	TArray<TObjectPtr<UFortChallengeBundleItemDefinition>> DonutBundles;

	UPROPERTY(EditAnywhere, Category="DonutChallengeScreen")
	TObjectPtr<UFortChallengeBundleItemDefinition> SkinUnlockBundle;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AttractChallengeDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BattlepassUpsell;

	UPROPERTY(Export, meta=(BindWidet, EditInline="true"))
	TObjectPtr<UCommonHierarchicalScrollBox> ScrollBox_Challenges;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Challenges;

};

