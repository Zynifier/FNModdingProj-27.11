// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSocialTypes.generated.h"

UENUM(BlueprintType)
enum class ELfgState : uint8
{
	NoResults = 0,
	Shuffling = 1,
	NoSocialTagsAdded = 2,
	LfgOff = 3,
	LfgUnavailable = 4,
	LfgOffNoSocialTags = 5,
	NoSocialTagsSelected = 6,
	// values used outside the LFG panel

	NoFriendsSuggestLFG = 7,
	RebootInvitePlayerButton = 8,
	RebootInviteAllRallied = 9,
	// LFG Buttons

	ChangeTagsButton = 10,
	ApplyButton = 11,
	ShuffleButton = 12,
	LfgOffSocialBan = 13,
};

UENUM(BlueprintType)
enum class ELocalUserOnlineStatus : uint8
{
	Online = 0,
	Offline = 1,
	Away = 2,
	ExtendedAway = 3,
	DoNotDisturb = 4,
	Chat = 5,
};

UENUM(BlueprintType)
enum class EMultiFriendAction : uint8
{
	AcceptFriendRequest = 0,
};

UENUM(BlueprintType)
enum class EReferFriendOrigin : uint8
{
	AddFriend = 0,
	PartyUp = 1,
};

