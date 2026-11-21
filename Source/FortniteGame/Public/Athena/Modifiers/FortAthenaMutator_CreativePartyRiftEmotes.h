// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modifiers/FortAthenaMutator_PartyRiftEmotes.h"
#include "FortAthenaMutator_CreativePartyRiftEmotes.generated.h"

class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortVolume;
class APlayerState;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativePartyRiftEmotes : public AFortAthenaMutator_PartyRiftEmotes
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCreativeProfilePermissionsUpdated(AFortPlayerControllerAthena* PlayerController);

	UFUNCTION()
	void HandleCreativeProfileSet(AFortPlayerController* PlayerController);

	UFUNCTION()
	void HandlePlayerEnteredVolume(APlayerState* PlayerState, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerExitedVolume(APlayerState* PlayerState, AFortVolume* Volume);

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_CreativePartyRiftEmotes")
	bool bForceAddEmotes;

};

