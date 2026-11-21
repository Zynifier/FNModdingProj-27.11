// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Announcement/FortClientAnnouncement.h"
#include "FortClientAnnouncement_Cinematic.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_Cinematic : public AFortClientAnnouncement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement|Cinematic")
	void OnPlayerSkippedCutscene();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Announcement|Cinematic")
	void OnEnteredCinematicState();

};

