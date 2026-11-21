// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PlayerDowned.generated.h"

USTRUCT(meta=(DisplayName="Player Downed"))
struct FFortVerbMessage_PlayerDowned : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	FSubjectTagsPair DownedPlayer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	FSubjectTagsPair Downer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	bool bIsHeadShot;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	bool bIsSaviorDBNO;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	bool bIsAvengerDBNO;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerDowned")
	float DownedDistance;

};

