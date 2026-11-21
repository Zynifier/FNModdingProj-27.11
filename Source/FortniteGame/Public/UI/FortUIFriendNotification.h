// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UI/FortUINotification.h"
#include "FortUIFriendNotification.generated.h"

UENUM(BlueprintType)
enum class EFortUIFriendNotificationType : uint8
{
	Default = 0,
	FriendRequest = 1,
	PartyInviteSent = 2,
	PartyInvite = 3,
	InviteFriendToParty = 4,
	PartyRequest = 5,
	AutoImportFriendSuggestion = 6,
	PartyMemberCreated = 7,
	PartyMemberLeft = 8,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortUIFriendNotification : public UFortUINotification
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortUIFriendActionNotification")
	EFortUIFriendNotificationType FriendActionType;

	UPROPERTY(BlueprintReadOnly, Category="FortUIFriendActionNotification")
	FUniqueNetIdRepl FriendUniqueId;

	UPROPERTY(BlueprintReadOnly, Category="FortUIFriendActionNotification")
	bool bShowTags;

};

