// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PlayerRevealed.generated.h"

USTRUCT(meta=(DisplayName="Player Revealed"))
struct FFortVerbMessage_PlayerRevealed : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerRevealed")
	FSubjectTagsPair RevealedPlayer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerRevealed")
	float DistanceToRevealedPlayer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerRevealed")
	FGameplayTagContainer TrackingTypeTags;

};

