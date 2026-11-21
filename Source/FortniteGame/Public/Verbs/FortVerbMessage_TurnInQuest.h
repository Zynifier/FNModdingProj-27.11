// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_TurnInQuest.generated.h"

USTRUCT()
struct FFortVerbMessage_TurnInQuest : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_TurnInQuest")
	FSubjectTagsPair NPC;

};

