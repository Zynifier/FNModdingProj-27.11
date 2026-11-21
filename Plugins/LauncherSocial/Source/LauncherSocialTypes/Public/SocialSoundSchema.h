// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SlateSound.h"
#include "SocialSoundSchema.generated.h"

USTRUCT()
struct FSocialSoundSchema
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sound", meta=(DisplayName="Message Received Sound"))
	FSlateSound MessageReceivedSound;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(DisplayName="Party Invite Received Sound"))
	FSlateSound PartyInviteReceivedSound;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(DisplayName="Friend Invite Received Sound"))
	FSlateSound FriendInviteReceivedSound;

};

