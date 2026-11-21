// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialGameplayContextEvent.generated.h"

class AActor;

USTRUCT()
struct FClientFinishedDownloadOnDemand
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FSpatialGameplayInterfaceContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="SpatialGameplayInterfaceContext")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

};

