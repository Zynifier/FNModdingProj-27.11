// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "FortDependantReplicationHelperComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent, DisableNativeTick))
class UFortDependantReplicationHelperComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortDependantReplicationHelperComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

