// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EncounterBlueprintLibrary.generated.h"

class AActor;
class UEncounterMobManagerComponent;

UCLASS()
class UEncounterBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Encounter", meta=(WorldContext="WorldContextObject"))
	static UEncounterMobManagerComponent* GetRelevantMobManagerComponentForActor(const AActor* Actor);

};

