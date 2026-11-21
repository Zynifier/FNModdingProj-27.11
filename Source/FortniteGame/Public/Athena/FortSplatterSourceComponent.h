// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortSplatterSourceComponent.generated.h"

class AActor;
class AFortSplineGroundPath;

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortSplatterSourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 AddPreviousSource(AActor* Actor);

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> PreviousSources;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortSplineGroundPath> FortSplineGroundPath;

};

