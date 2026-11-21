// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortDeathCauseEnum.h"
#include "Unicorn/Social/UnicornSocialTypes.h"
#include "UnicornTypes.generated.h"

UENUM()
enum class EHighlightReelIds : uint8
{
	INVALID = 0,
	MainHighlightReel = 1,
	ShortHighlightReel = 2,
	MicroHighlights = 3,
	EntireGameReel = 4,
	ShortExtendedHighlightReel = 5,
	MediumHighlightReel = 6,
	MediumExtendedHighlightReel = 7,
	ShorterHighlightReel = 8,
	PlayerSpotlightReel = 9,
	PlayerSpotlightNoDeathsReel = 10,
	VATReel = 11,
	COUNT = 12,
};

USTRUCT()
struct FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float TimeStamp;

	UPROPERTY()
	FVector Location;

};

USTRUCT()
struct FBuildEvent : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsEdit;

};

USTRUCT()
struct FPawnSample : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	float Health;

	UPROPERTY()
	float Shield;

	UPROPERTY()
	uint8 bIsJumpingOrFalling : 1;

	UPROPERTY()
	uint8 bIsInVehicle : 1;

	UPROPERTY()
	uint8 bIsParachuteOpen : 1;

	UPROPERTY()
	uint8 bIsDBNO : 1;

	UPROPERTY()
	uint8 bIsDead : 1;

	UPROPERTY()
	uint8 bIsSwimming : 1;

	UPROPERTY()
	int16 POITag;

};

USTRUCT()
struct FDeathEvent : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl Instigator;

	UPROPERTY()
	FUniqueNetIdRepl Victim;

	UPROPERTY()
	bool bIsDBNO;

	UPROPERTY()
	bool bWasDBNOOnDeath;

	UPROPERTY()
	EDeathCause DeathCause;

	UPROPERTY()
	float DeathDistance;

	UPROPERTY()
	FPawnSample PawnSampleBeforeDeath;

	UPROPERTY()
	FGameplayTagContainer DeathTags;

	UPROPERTY()
	FGameplayTagContainer VictimTags;

	UPROPERTY()
	FGameplayTagContainer KillerTags;

};

USTRUCT()
struct FPlayerDancePartySample : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUnicornDancePartyInfo DancePartyInfo;

};

USTRUCT()
struct FPlayerMetaInfo : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MatchPlacement;

};

USTRUCT()
struct FStormSample : public FBaseSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Radius;

	UPROPERTY()
	bool bIsValid;

};

