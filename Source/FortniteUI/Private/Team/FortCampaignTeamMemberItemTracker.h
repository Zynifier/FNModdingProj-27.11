// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortCampaignTeamMemberEntry.h"
#include "FortCampaignTeamMemberItemTracker.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignTeamMemberItemTracker : public UFortCampaignTeamMemberEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTrackedItemsUpdated();

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberItemTracker")
	TArray<FString> TemplateIdsToTrack;

};

