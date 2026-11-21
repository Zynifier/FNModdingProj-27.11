// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_KillCredit.generated.h"

USTRUCT()
struct FFortVerbMessage_KillCredit : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillCredit")
	FSubjectTagsPair KilledActor;

};

