// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientEvent.h"
#include "FortClientEventInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI)
class UFortClientEventInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="ClientEvent", meta=(BlueprintInternalUseOnly="true"))
	void BlueprintCustomHandleClientEvent(UObject* EventSource, UObject* EventFocus, const FFortClientEvent& ClientEvent);

};

