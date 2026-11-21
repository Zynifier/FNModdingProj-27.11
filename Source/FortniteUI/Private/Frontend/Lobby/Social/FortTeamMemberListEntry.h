// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortPresenceUserListEntry.h"
#include "FortTeamMemberListEntry.generated.h"

class UFortPartyStatusIcon;
class UFortVoiceChatStatusIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTeamMemberListEntry : public UFortPresenceUserListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPartyStatusIcon> PartyIcon_Status;

};

