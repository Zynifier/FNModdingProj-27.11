// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Interact.generated.h"

USTRUCT()
struct FFortFortVerbMessage_Interact : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortFortVerbMessage_Interact")
	FSubjectTagsPair Target;

};

