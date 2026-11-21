// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "CreativeIslandSettingsComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCreativeIslandSettingsComponent : public UActorComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

};

