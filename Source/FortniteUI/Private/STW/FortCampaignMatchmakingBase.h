// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Party/PartyTypes.h"
#include "FortCampaignMatchmakingBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignMatchmakingBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerParticipatingInParty() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnGameReadinessChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartyPrivacyChanged(EPartyType PartyType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamMembershipChanged();

};

