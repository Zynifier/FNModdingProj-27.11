// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_ConvertNPC.generated.h"

USTRUCT()
struct FFortVerbMessage_ConvertNPC : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ConvertNPC")
	FSubjectTagsPair ConvertedNPC;

};

