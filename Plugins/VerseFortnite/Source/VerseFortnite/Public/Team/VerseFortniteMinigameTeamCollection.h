// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseFortniteMinigameTeamCollection.generated.h"

class AActor;
class AFortMinigame;

UCLASS(Abstract)
class UVerseFortniteMinigameTeamCollection : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnMinigameDestroyed(AActor* DestroyedMinigame);

	UFUNCTION()
	void OnMinigameSetup(AFortMinigame* InMinigame);

};

