// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "StateDrivenFloat.generated.h"

USTRUCT(BlueprintType)
struct FStateDrivenFloat
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenFloat", meta=(BaseStruct="/Script/StateDrivenActorRuntime.StateDrivenFloat_Base", ExcludeBaseStruct))
	FInstancedStruct InstancedFloat;

};

USTRUCT(BlueprintType, meta=(Hidden))
struct FStateDrivenFloat_Base
{
	GENERATED_BODY()

};

