// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_Event.h"
#include "FortEventName.h"
#include "K2Node_HandleClientEvent.generated.h"

UCLASS(MinimalAPI)
class UK2Node_HandleClientEvent : public UK2Node_Event
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventOptions")
	FFortClientEventName ClientEventName;

};

