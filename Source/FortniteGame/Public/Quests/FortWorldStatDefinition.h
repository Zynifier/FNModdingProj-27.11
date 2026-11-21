// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InstancedStruct.h"
#include "FortWorldStatDefinition.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortWorldStatDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortWorldStatDefinition", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct))
	TArray<FInstancedStruct> WorldStats;

};

