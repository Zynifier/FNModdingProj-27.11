// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"
#include "K2Node_GetBlueprintContext.generated.h"

class USubsystem;

UCLASS()
class BLUEPRINTCONTEXTEDITOR_API UK2Node_GetBlueprintContextEx : public UK2Node
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<USubsystem> CustomClass;

};

