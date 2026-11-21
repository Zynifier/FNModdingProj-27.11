// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortNearbyActorsPerceptionComponent.h"
#include "FortAINearbyActorsPerceptionComponent.generated.h"

class IFortAthenaAILODSettings;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAINearbyActorsPerceptionComponent : public UFortNearbyActorsPerceptionComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IFortAthenaAILODSettings> CachedLODSettingsManager;

};

