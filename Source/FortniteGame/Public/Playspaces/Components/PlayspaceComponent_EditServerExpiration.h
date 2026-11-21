// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/PlayspaceComponent_ServerExpiration.h"
#include "PlayspaceComponent_EditServerExpiration.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_EditServerExpiration : public UPlayspaceComponent_ServerExpiration
{
	GENERATED_BODY()

};

