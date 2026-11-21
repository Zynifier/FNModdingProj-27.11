// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/FortLevelSpawnActor.h"
#include "FortSpawnedScoreActor.generated.h"

class APlayerState;

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortSpawnedScoreActor : public AFortLevelSpawnActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Score")
	void OnScoreActorCollected(APlayerState* PlayerState);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Score")
	FGameplayTagContainer GameplayTags;

};

