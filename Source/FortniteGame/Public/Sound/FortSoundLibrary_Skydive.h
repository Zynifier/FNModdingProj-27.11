// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Sound/FortSoundLibraryComponents.h"
#include "Sound/FortSoundLibraryContexts.h"
#include "FortSoundLibrary_Skydive.generated.h"

class AFortPlayerPawn;
class UFortSoundIndicatorComponent;

UCLASS(BlueprintType, HideCategories=("Tags", "ComponentReplication", "Sockets", "Activation", "Cooking", "Collision", "ComponentTick", "AssetUserData", "Replication", "Variable", "Navigation"))
class UFortSkydiveSoundLibraryComponent : public UFortSoundLibraryComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBeginSkydiving();

	UFUNCTION()
	void HandleEndSkydiving();

	UFUNCTION()
	void HandlePlayerLoadoutApplied(const FFortAthenaLoadout& NewLoadout);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

};

UCLASS(BlueprintType)
class UFortSkydiveSoundLibraryContext : public UFortSoundLibraryContext
{
	GENERATED_BODY()

};

