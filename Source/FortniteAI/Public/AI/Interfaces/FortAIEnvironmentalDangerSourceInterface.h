// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAIEnvironmentalDangerSourceInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIEnvironmentalDangerSourceInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAIEnvironmentalDangerSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	float GetDangerAtLocation(const FVector& Location) const;

	UFUNCTION(BlueprintNativeEvent)
	bool GetDangerSourceActive() const;

	UFUNCTION(BlueprintNativeEvent)
	FBox GetDangerSourceBounds() const;

};

