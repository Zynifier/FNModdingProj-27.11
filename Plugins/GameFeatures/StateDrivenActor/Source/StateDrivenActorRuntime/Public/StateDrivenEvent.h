// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueInterface.h"
#include "StateDrivenEvent.generated.h"

class UFortActorComponent_StateDriven;
class UGameplayEffect;

USTRUCT(BlueprintType, meta=(Hidden))
struct STATEDRIVENACTORRUNTIME_API FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent")
	FGameplayCueTag BurstGameplayCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActorComponent_StateDriven> StateDrivenOwner;

};

