// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortSupplyDropRadioAttachActorComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortSupplyDropRadioAttachActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Supply Drop Radio")
	void SetOwningActorNetCullDistance(const float DistanceSquared) const;

};

