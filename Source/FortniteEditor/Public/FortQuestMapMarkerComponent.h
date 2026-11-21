// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortQuestMapMarkerComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortQuestMapMarkerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortQuestMapMarkerComponent")
	FGameplayTag QuestMapMarkerTag;

};

