// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "FortInitializationInterface.h"
#include "FortLevelScriptActor.generated.h"

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"), meta=(ChildCanTick, ScriptName="FortLevelScriptActor"))
class AFortLevelScriptActor : public ALevelScriptActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	FORTNITEGAME_API void OnMatchStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	FORTNITEGAME_API void OnWorldReady();

private:
	UPROPERTY(Transient)
	uint8 bWorldReadyCalled : 1;

};

