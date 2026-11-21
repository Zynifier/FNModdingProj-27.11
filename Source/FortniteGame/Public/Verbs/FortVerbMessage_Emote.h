// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Emote.generated.h"

USTRUCT()
struct FFortVerbMessage_Emote : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Emote")
	FSubjectTagsPair Emote;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Emote")
	FSubjectTagsPair Target;

};

