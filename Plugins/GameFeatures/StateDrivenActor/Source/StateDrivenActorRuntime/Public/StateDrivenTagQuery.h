// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "StateDrivenTagQuery.generated.h"

USTRUCT(BlueprintType)
struct FStateDrivenTagQuery
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenTagQuery", meta=(BaseStruct="/Script/StateDrivenActorRuntime.StateDrivenTagQuery_Base", ExcludeBaseStruct))
	FInstancedStruct InstancedTagQuery;

};

USTRUCT(BlueprintType, meta=(Hidden))
struct FStateDrivenTagQuery_Base
{
	GENERATED_BODY()

};

