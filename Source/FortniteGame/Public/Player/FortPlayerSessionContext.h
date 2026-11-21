// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "FortPlayerSessionContext.generated.h"

UCLASS(MinimalAPI)
class UFortPlayerSessionContext : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FGameplayTag> DiscoveredPoiTags;

};

