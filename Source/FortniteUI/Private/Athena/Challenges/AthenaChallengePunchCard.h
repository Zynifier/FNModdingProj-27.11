// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Misc/DateTime.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "AthenaChallengePunchCard.generated.h"

class UCommonTextBlock;
class UDynamicEntryBox;
class UFortChallengeBundleItem;
class UFortChallengeBundleItemDefinition;
class UFortQuestItem;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengePunchCard : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FinishedPunchingCard(bool bPlayOutro);

	UFUNCTION(BlueprintImplementableEvent)
	void FocusPunchCard();

	UFUNCTION(BlueprintImplementableEvent)
	void HideProgressCount(bool bBundleCompleted);

	UFUNCTION(BlueprintImplementableEvent)
	void SetBangState(bool bShowBang);

	UFUNCTION(BlueprintImplementableEvent)
	void SetProgressCount(int32 AchivedCount, int32 GoalCount);

	UFUNCTION(BlueprintImplementableEvent)
	void SetStyle(const FFortChallengePunchCardStyles& PunchStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUnkownState(bool bKnown);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUpEncodedName(const FString& Name, int32 Count);

	UFUNCTION(BlueprintCallable)
	void TryToClearBangState();

	UFUNCTION(BlueprintImplementableEvent)
	void UnfocusPunchCard();

	UFUNCTION()
	void UpdateChallengePunchCard(const UFortChallengeBundleItem* Bundle, const UFortQuestItem* CopmpletedQuest);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowWidget();

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengePunchCard")
	int32 MaxPunchesAllowed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> Box_PunchSlots;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengePunchCard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengePunchCard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

private:
	UPROPERTY(Transient)
	bool bInitializedWidgetPool;

	UPROPERTY(Transient)
	bool bBundleIsKnown;

	UPROPERTY(Transient)
	bool bBangShown;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortChallengeBundleItemDefinition> WeakBundleDef;

	UPROPERTY(Transient)
	FDateTime MostRecentPunch;

};

