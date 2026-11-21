// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortPlayerStateComponent_VictoryCrowns.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_VictoryCrowns : public UFortPlayerStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetWonRoyalRoyale() const;

private:
	UPROPERTY(Transient, Replicated)
	bool bHasWonRoyalRoyale;

};

