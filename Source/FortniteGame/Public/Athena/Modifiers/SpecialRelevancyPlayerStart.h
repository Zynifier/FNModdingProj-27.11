// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPlayerStartWarmup.h"
#include "SpecialRelevancyPlayerStart.generated.h"

class AFortPlayerControllerAthena;

UCLASS(MinimalAPI, HideCategories=("Collision", "Lighting", "LightColor", "Force"), ClassGroup=("Common"))
class ASpecialRelevancyPlayerStart : public AFortPlayerStartWarmup
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<TObjectPtr<AFortPlayerControllerAthena>, int32> RelevancyGroups;

};

