// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_MatchFinished.generated.h"

USTRUCT()
struct FFortVerbMessage_MatchFinished : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_MatchFinished")
	FSubjectTagsPair MatchMetaData;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_MatchFinished")
	int32 PlayerRank;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_MatchFinished")
	int32 PlayersOutLived;

};

