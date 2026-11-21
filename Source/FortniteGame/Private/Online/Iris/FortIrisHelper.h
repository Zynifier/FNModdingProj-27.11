// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortIrisHelper.generated.h"

class AActor;
class AFortPlayerController;
class APawn;
class APlayerState;

UCLASS(Transient)
class UFortIrisHelper : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnGameStatePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnPlayerControllerViewTargetChanged(AFortPlayerController* PC, AActor* NewViewTarget, AActor* OldViewTarget);

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

};

