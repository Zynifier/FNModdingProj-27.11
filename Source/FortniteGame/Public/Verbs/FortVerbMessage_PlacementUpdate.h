// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PlacementUpdate.generated.h"

class AActor;

USTRUCT()
struct FFortVerbMessage_PlacementUpdate : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlacementUpdate")
	int32 CurrentPlacement;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlacementUpdate")
	int32 PlayersAlive;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlacementUpdate")
	FSubjectTagsPair PlayerThatSetPlacement;

	UPROPERTY()
	TArray<TWeakObjectPtr<AActor>> AlivePlayersArray;

};

