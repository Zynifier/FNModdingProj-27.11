// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/GameStateComponents/FortGameStateComponent_DynamicStreamingLevel.h"
#include "FortGameStateComponent_DynamicVaultLevel.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_DynamicVaultLevel : public UFortGameStateComponent_DynamicStreamingLevel
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Worlds")
	bool bAutomaticallyLoadLevels;

	UPROPERTY(EditDefaultsOnly, Category="Worlds")
	bool bUseLoadingScreen;

};

