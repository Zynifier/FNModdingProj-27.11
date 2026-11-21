// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Math/MathFwd.h"
#include "FortCreativeRealEstatePlotManager.generated.h"

class UFortCreativeRealEstatePlotItemDefinition;

USTRUCT(BlueprintType)
struct FActiveRealEstatePlotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortCreativeRealEstatePlotItemDefinition> Plot;

	UPROPERTY()
	FVector Position;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCreativeRealEstatePlotManager : public AInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Replicated)
	TArray<FActiveRealEstatePlotInfo> ActiveCreativeRealEstatePlots;

};

