// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_SidewaysDimension.generated.h"

class UAthenaAIServiceLoot;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_SidewaysDimension : public UFortPlayspaceComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServiceLoot> CachedAIServiceLoot;

};

