// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Items/FortPickup.h"
#include "FortDeployableBasePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortDeployableBasePickup : public AFortPickup
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	FUniqueNetIdRepl AssociatedPlotOccupant;

};

