// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortInfluenceMap.generated.h"

class AFortNavigationGraph;
class UObject;

UCLASS()
class UFortInfluenceMap : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI|InfluenceMap", meta=(DisplayName="AddInfluenceSource", WorldContext="WorldContext"))
	static void K2_AddInfluenceSource(UObject* WorldContext, const FVector& Position, const FString& SourceName, float Strength = 1.000000f);

	UFUNCTION(BlueprintCallable, Category="AI|InfluenceMap", meta=(DisplayName="GetInfluenceSources", WorldContext="WorldContext"))
	static void K2_GetInfluenceSourcePositions(UObject* WorldContext, TArray<FVector>& InfluenceSourcePositions);

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortNavigationGraph> GraphData;

};

