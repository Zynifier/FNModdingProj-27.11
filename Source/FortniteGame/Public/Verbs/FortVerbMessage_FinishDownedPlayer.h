// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_FinishDownedPlayer.generated.h"

USTRUCT()
struct FFortVerbMessage_FinishDownedPlayer : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_FinishDownedPlayer")
	FSubjectTagsPair DownedPlayer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_FinishDownedPlayer")
	FSubjectTagsPair DamageSource;

};

