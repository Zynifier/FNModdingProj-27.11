// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortEventLevelNavigationBangVisualComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortEventLevelNavigationBangVisualComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortEventLevelNavigationBangVisualComponent")
	FGameplayTag BangTrackerTag;

};

