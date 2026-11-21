// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_ScoredPlayerElimination.generated.h"

USTRUCT()
struct FFortVerbMessage_ScoredPlayerElimination : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ScoredPlayerElimination")
	FSubjectTagsPair KilledFortPawn;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ScoredPlayerElimination")
	FSubjectTagsPair KillerTags;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ScoredPlayerElimination")
	float Distance;

};

