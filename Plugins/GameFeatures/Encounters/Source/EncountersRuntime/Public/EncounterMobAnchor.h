// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "EncounterMobAnchor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AEncounterMobAnchor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagContainer FilterTags;

};

