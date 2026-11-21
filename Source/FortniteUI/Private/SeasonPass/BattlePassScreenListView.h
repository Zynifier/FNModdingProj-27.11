// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Components/ListViewBase.h"
#include "CommonButtonLegacy.h"
#include "BattlePassScreenListView.generated.h"

class UCommonTextBlock;
class UFortItem;
class UTexture2D;

UCLASS(meta=(EntryClass="FortBattlePassRewardEntry"))
class UBattlePassScreenListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UBattlePassScreenListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="List Entries")
	float StartSpacing;

	UPROPERTY(EditAnywhere, Category="List Entries")
	float EndSpacing;

	UPROPERTY(EditAnywhere, Category="BattlePassScreenListView")
	float CycleSocialPlayerRate;

};

UCLASS(Abstract)
class UFortBattlePassRewardEntry : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void FadeInSocialUser();

	UFUNCTION(BlueprintImplementableEvent)
	void FadeOutSocialUser(bool bCallback);

	UFUNCTION(BlueprintCallable)
	void OnFadeOutSocialUserComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadSocialIcon(bool bSuccess, UTexture2D* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotateReward(int32 Index);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetReward(UFortItem* InReward, int32 TierLevel, float TierProgress, bool bIsLastEntry, bool bHasAdditionalStylesToDisplay, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bIsFreeItem, bool bOwnsBattlePass, int32 SeasonLevel, bool bIsFirstEntry);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetRotatingReward(UFortItem* InReward, bool bHasAdditionalStylesToDisplay, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bIsFreeItem, bool bOwnsBattlePass, int32 SeasonLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSocialPlayerProgress(float Progress);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassRewardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SocialUserName;

};

