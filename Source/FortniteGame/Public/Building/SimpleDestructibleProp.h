// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/SimpleDestructiblePropInterface.h"
#include "FortStaticMeshActor.h"
#include "SimpleDestructibleProp.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(DisplayName="Simple Destructible Prop"))
class ASimpleDestructibleProp : public AFortStaticMeshActor, public ISimpleDestructiblePropInterface
{
	GENERATED_BODY()

};

