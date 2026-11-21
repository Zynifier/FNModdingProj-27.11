// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CrewScreenContentBlockingInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCrewScreenContentBlockingInterface : public UInterface
{
	GENERATED_BODY()
};

class ICrewScreenContentBlockingInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BlockScreenContent(const bool bBlockScreen, const FText& ContentBlockedText);

};

