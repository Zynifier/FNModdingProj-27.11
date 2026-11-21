// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortCampaignTeamMemberEntry.h"
#include "FortCampaignTeamMemberBanner.generated.h"

class UFortPlayerBanner;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignTeamMemberBanner : public UFortCampaignTeamMemberEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_MemberBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LeaderIcon;

};

