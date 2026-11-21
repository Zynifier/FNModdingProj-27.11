// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Team/FortCampaignTeamMemberEntry.h"
#include "FortCampaignTeamMemberResult.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortPlayerBanner;
class UFortPlayerPowerRating;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignTeamMemberResult : public UFortCampaignTeamMemberEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateMemberWithUniqueNetID(const FUniqueNetIdRepl& MemberId);

protected:
	UFUNCTION(BlueprintCallable)
	void Focus();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignTeamMemberResult", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Stats;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_MemberBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> PowerRatingWidgetSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Moonbeam_PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MemberName;

};

