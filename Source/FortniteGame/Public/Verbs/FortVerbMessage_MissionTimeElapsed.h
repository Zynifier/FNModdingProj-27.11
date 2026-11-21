// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_MissionTimeElapsed.generated.h"

USTRUCT()
struct FFortVerbMessage_MissionTimeElapsed : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_MissionTimeElapsed")
	FGameplayTagContainer MissionTags;

};

