// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PawnEliminated.generated.h"

USTRUCT()
struct FFortVerbMessage_PawnEliminated : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	FSubjectTagsPair EliminatedPawn;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	FSubjectTagsPair Killer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	FSubjectTagsPair EliminationSource;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	float Distance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	bool bKilledPawnWasPlayer;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	bool bKilledPawnWasWildlife;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	bool bWasEliminatedByConvertedPawn;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnEliminated")
	int32 TotalDamageDoneByContributors;

};

USTRUCT(BlueprintType)
struct FKillContributor
{
	GENERATED_BODY()

};

