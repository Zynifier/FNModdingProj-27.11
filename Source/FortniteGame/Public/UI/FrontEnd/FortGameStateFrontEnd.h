// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameState.h"
#include "FortGameStateFrontEnd.generated.h"

class AFortFrontEndMiniMapManager;
class IFortMiniMapInterface;
class UGameStateComponent;

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateFrontEnd : public AFortGameState
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IFortMiniMapInterface> MiniMapInterface;

	UPROPERTY(Transient)
	TSubclassOf<AFortFrontEndMiniMapManager> MiniMapManagerClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UGameStateComponent*> RegisteredSTWComponents;

};

