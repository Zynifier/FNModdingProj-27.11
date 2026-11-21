// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortBasicTeamMemberEntry.h"
#include "FortTeamMemberPedestalNameplate.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortHabaneroTierWidget;
class UFortPlayerPowerRating;
class UImage;
class UMatchmakingInputIndicatorBase;
class USizeBox;
enum class EFortFriendRequestStatus : uint8;
enum class EGameReadiness : uint8;
enum class ESubGame : uint8;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTeamMemberPedestalNameplate : public UFortBasicTeamMemberEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCurrentSubGameChanged(ESubGame NewSubGame);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendStatusUpdated(const EFortFriendRequestStatus FriendRequestStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsPlayingHabaneroChanged(bool bPlayingHabanero);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPedestalSelectedChanged(bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayReadyAudio(bool bIsReadyForMatchmaking);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReadyStatusChanged(EGameReadiness GameReadiness, bool bIsDownloading);

private:
	UFUNCTION()
	void HandleShouldShowPhoenixDisplayChanged(bool bShouldShowPhoenixDisplay);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTeamMemberPedestalNameplate", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ReadyStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMatchmakingInputIndicatorBase> InputIndicator_ActiveInputType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> PowerRatingWidgetSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> PowerRating_CampaignPower;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Moonbeam_PowerRating_CampaignPower;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Phoenix_PowerRating_CampaignPower;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_HotfixControlled;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerLevel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HeroIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTeamMemberPedestalNameplate", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddFriend;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTeamMemberPedestalNameplate", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortHabaneroTierWidget> HabaneroWidget;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortTeamMemberPedestalNameplate", meta=(AllowPrivateAccess="TRUE"))
	bool bTeamMemberPedestalNameplateAddFriendButtonEnabled;

};

