// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortProtoActorBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortProtoActorBase : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Proto")
	void SetStreamingPriority(float Value);

};

