// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortPresenceUserListEntry.h"
#include "FortVoiceChatMemberListEntry.generated.h"

class UFortPartyStatusIcon;
class UFortVoiceChatStatusIcon;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortVoiceChatMemberListEntry : public UFortPresenceUserListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPartyStatusIcon> PartyIcon_Status;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChatMemberListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Crown;

};

