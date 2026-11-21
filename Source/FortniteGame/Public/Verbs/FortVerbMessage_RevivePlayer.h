// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_RevivePlayer.generated.h"

USTRUCT()
struct FFortVerbMessage_RevivePlayer : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_RevivePlayer")
	bool bRevivedSquadMember;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_RevivePlayer")
	bool bSelfRevived;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_RevivePlayer")
	FSubjectTagsPair RevivedPlayer;

};

