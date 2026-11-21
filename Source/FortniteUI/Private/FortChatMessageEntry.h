// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chat/SocialChatMessageEntry.h"
#include "FortChatMessageEntry.generated.h"

enum class EChatMessageOrigin : uint8;

UENUM(BlueprintType)
enum class EChatMessageOrigin : uint8
{
	// Sent by a local player

	Local = 0,
	// Sent by an online player

	Remote = 1,
	// Sent by the system 

	System = 2,
	// Sender unknown or message invalid

	Unknown = 3,
};

UCLASS(Abstract)
class UFortChatMessageEntry : public USocialChatMessageEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	EChatMessageOrigin GetMessageOrigin() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnFocusedChanged(bool bIsFocused);

};

