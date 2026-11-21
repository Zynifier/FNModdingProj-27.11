// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortCampaignTeamMemberEntry.h"
#include "FortCampaignTeamMemberInfo.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortPlayerBanner;
class UFortPlayerPowerRating;
class UFortSocialNameTextBlock;
class UFortVoiceChatStatusIcon;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignTeamMemberInfo : public UFortCampaignTeamMemberEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalTeamMemberParticipationChanged(bool bIsParticipating);

private:
	UFUNCTION()
	void HandleShouldShowPhoenixDisplayChanged(bool bShouldShowPhoenixDisplay);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MenuButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_MemberBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> PowerRatingWidgetSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Moonbeam_PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Phoenix_PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialNameTextBlock> Text_MemberName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LeaderIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Fortitude;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Offense;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Resistance;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Technology;

};

