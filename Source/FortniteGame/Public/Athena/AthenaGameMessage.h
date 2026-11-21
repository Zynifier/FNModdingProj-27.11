// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaGameMessage.generated.h"

class APlayerController;
class UMediaSource;
class USoundCue;

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EAthenaGameMessageDataFlags : uint8
{
	None = 0,
	// The DefaultCriticalMessage shows an Exclamation by default.  This can disable that animation to allow for a priority critical message, without exclamation

	DisableCreativeExclamation = 1,
};

UENUM(BlueprintType)
enum class EAthenaGameMsgType : uint8
{
	// no message

	None = 0,
	// Default intro letting everyone know the goal

	DefaultIntro = 1,
	// Default generic message

	DefaultMessage = 2,
	// Default critical/important message

	DefaultCriticalMessage = 3,
	// Comm intro message

	CommIntro = 4,
	// Comm normal message

	CommMessage = 5,
	// Comm critical/important message

	CommCriticalMessage = 6,
	// Corner intro message

	CornerIntro = 7,
	// Corner normal message

	CornerMessage = 8,
	// Corner critical/important message

	CornerCriticalMessage = 9,
	// Respawn turning off warning

	RespawnTurningOffWarning = 10,
	// Respawn off warning

	RespawnOffWarning = 11,
	// center screen message

	CenterMessage = 12,
	// center screen important message

	CenterImportantMessage = 13,
	// center screen critical message

	CenterCriticalMessage = 14,
};

USTRUCT(BlueprintType)
struct FAthenaGameMessageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	EAthenaGameMsgType MsgType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData", meta=(MultiLine="TRUE"))
	FText MsgText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	TObjectPtr<USoundCue> MsgSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	TObjectPtr<UMediaSource> MsgMediaSource;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	float MsgDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	bool bIsTeamBased;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	int32 TeamIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	float DisplayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaGameMessageData")
	EAthenaGameMessageDataFlags MessageFlags;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AthenaGameMessageData")
	TObjectPtr<APlayerController> TargetPlayerController;

};

