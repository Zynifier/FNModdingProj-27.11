// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TimeOfDayInhibitorInterface.generated.h"

UINTERFACE(BlueprintType)
class UTimeOfDayInhibitor : public UInterface
{
	GENERATED_BODY()
};

class ITimeOfDayInhibitor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool IsInhibitionEnabled() const;

	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	void OnDominantChanged(bool bIsDominant);

};

