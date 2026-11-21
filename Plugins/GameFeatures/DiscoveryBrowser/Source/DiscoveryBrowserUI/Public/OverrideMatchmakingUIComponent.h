// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortUITypes.h"
#include "OverrideMatchmakingUIComponent.generated.h"

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable)
class UOverrideMatchmakingUIComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="OverrideMatchmakingUIComponent")
	FMatchmakingUIOverride MatchmakingUIOverride;

};

