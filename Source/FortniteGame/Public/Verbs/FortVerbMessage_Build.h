// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Build.generated.h"

USTRUCT()
struct FFortVerbMessage_Build : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Build")
	int32 ResourcesSpent;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Build")
	FSubjectTagsPair Building;

};

