// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortPresenceUserListEntry.h"
#include "FortPartyMemberListEntry.generated.h"

class UFortVoiceChatStatusIcon;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPartyMemberListEntry : public UFortPresenceUserListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortPartyMemberListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Crown;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

};

