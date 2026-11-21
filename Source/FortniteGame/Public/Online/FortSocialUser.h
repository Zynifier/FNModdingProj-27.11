// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "User/SocialUser.h"
#include "FortSocialUser.generated.h"

class UTexture2D;

UENUM()
enum class EFortSocialFriendRequestMethod : uint8
{
	/** Friend Request was sent using the "Add Friend" button in the player's TeamMemberPedestalNameplate */
	LobbySuggestion = 0,
	/** Friend Request was sent using the "Add Friend" in the FortLobbyPlayerPanel */
	LobbyPlayerPanel = 1,
	/** Friend Request was sent using UFortSocialToolkit::TryMassImportPlatformFriends() */
	MassImportPlatformFriends = 2,
	/** Friend Request was sent while UFortSocialToolkit::bAutoImportPlatformFriends was enabled and a new platform friend user was added to the OnlyFriendsOnPlatformList */
	AutoImportPlatformFriends = 3,
	/** Friend Request was sent using FPartyContextRewriteHelper */
	PartyContextRewriteHelper = 4,
	/** Friend Request was sent using SocialInteraction_AddFriend */
	SocialInteraction_AddFriend = 5,
	/** Friend Request was sent using SocialInteraction_AddPlatformFriend */
	SocialInteraction_AddPlatformFriend = 6,
};

UENUM()
enum class ESocialTagsChangeReason : uint8
{
	// Change comes from MCP Tags service

	Service = 0,
	// Change comes from the Social Tags editor

	Editor = 1,
};

UCLASS(Config=Game, MinimalAPI)
class UFortSocialUser : public USocialUser
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> AvatarImageLarge;

	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> AvatarImageSmall;

};

