// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortClientEventInterface.h"
#include "FortResultsWidget.generated.h"

class UCommonUserWidget;
class UFortItem;
enum class EFortCompletionResult : uint8;
enum class EFortRewardItemType : uint8;

UENUM(BlueprintType)
enum class EFortRewardItemType : uint8
{
	RewardedBadges = 0,
	MissedBadges = 1,
	RewardedItems = 2,
	RewardedAccountItems = 3,
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResultsWidget : public UCommonActivatablePanelLegacy, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Zone Rewards")
	void GetRewardsByType(EFortRewardItemType Type, TArray<UFortItem*>& OutRewards);

	UFUNCTION(BlueprintCallable, Category="Zone Rewards")
	int32 GetTotalMissionPointsEarned();

	UFUNCTION(BlueprintPure, Category="Zone Completion")
	EFortCompletionResult GetZoneCompletionResult() const;

	UFUNCTION(BlueprintPure, Category="Zone Completion")
	FText GetZoneCompletionResultText() const;

	UFUNCTION(BlueprintPure, Category="Zone Rewards")
	bool IsDataFinalized() const;

	UFUNCTION(BlueprintCallable, Category="Zone Completion")
	void LogXPData();

	UFUNCTION(BlueprintCallable, Category="Zone Completion")
	void RequestExitZone();

	UFUNCTION(BlueprintCallable, Category="Zone Completion Analytics")
	void SendEndOfRoundFriendInviteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName);

	UFUNCTION(BlueprintCallable, Category="Zone Completion Analytics")
	void SendEndOfRoundScreenAnalytic(const FString& ScreenName, bool Skipped, float TimeSpent);

	UFUNCTION(BlueprintCallable, Category="Zone Completion Analytics")
	void SendEndOfRoundUpVoteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName);

	UFUNCTION(BlueprintCallable, Category="Zone Completion")
	void TriggerSetupTeleportCameraEvent();

protected:
	UFUNCTION(BlueprintCallable, Category="Zone Completion|Emote")
	virtual void HandleEmoteClicked(bool& bPassThrough);

	UFUNCTION(BlueprintCallable, Category="Zone Completion|Emote")
	virtual void HandlePickerCancel(bool& bPassThrough);

	UFUNCTION(BlueprintCallable, Category="Zone Completion")
	void ToggleChat(bool bShow);

private:
	UPROPERTY()
	int32 AdditionalGrantedMissionPoints;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RewardedBadges;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> MissedBadges;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RewardedItems;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RewardedAccountItems;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResultsWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Radial_Picker;

};

