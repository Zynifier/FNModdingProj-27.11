// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UnicornSocialTypes.generated.h"

UENUM()
enum class EUnicornSocialFeatures : uint8
{
	INVALID = 0,
	FriendPlay = 1,
	DancePartyManpower = 2,
	CongaLineManpower = 3,
	SocialPartyDuration = 4,
	COUNT = 5,
};

USTRUCT()
struct FUnicornDancePartyInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float StartTimestamp;

	UPROPERTY()
	float EndTimestamp;

	UPROPERTY()
	int32 PeakMembers;

	UPROPERTY()
	float PeakStartTimestamp;

	UPROPERTY()
	float PeakEndTimestamp;

	UPROPERTY()
	bool bEndsBecauseOfUs;

	UPROPERTY()
	bool bIsMovingEmote;

	UPROPERTY()
	TSet<FUniqueNetIdRepl> LatestMembers;

};

