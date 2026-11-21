// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_PlayerPawnOverrides.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_PlayerPawnOverrides : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlayerPawnOverrides")
	bool bAllowPlayersUnderLandscape;

};

