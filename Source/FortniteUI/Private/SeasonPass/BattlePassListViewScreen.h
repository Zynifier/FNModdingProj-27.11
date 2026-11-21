// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "BattlePassListViewScreen.generated.h"

class UAthenaSeasonItemData_Level;
class UAthenaSeasonItemDefinition;
class UBattlePassLeaderboard;
class UBattlePassScreenListView;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassListViewScreen : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleOnUpdatedVisibleFriendCount(int32 LeftFriendCount, int32 RightFriendCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHandleFriendLeaderboard();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHandleRotateReward();

	UPROPERTY(EditAnywhere, Category="BattlePassListViewScreen")
	TSubclassOf<UBattlePassLeaderboard> FriendLeaderboardClass;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenListView> ListView_Rewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassListViewScreen", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SocialUserRightCounter;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassListViewScreen", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SocialUserLeftCounter;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> CachedSeasonData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_Level> CachedSeasonData_Level;

	UPROPERTY(Transient)
	TArray<FBattlePassRewardInfo> AllActiveSeasonRewards;

};

