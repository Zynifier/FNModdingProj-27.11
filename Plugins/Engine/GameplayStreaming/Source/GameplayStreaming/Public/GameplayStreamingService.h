// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayStreamingService.generated.h"

class UBaseGameplayStreamingHandler;

/**
 * Class to handle all gameplay streaming logic. When calls are made to the streaming interface, the streaming interface 
 * will defer to it's ActiveHandler, which will query the corresponding platform gdk (XGameStreaming gdk in the case of helios),
 * potentially through a wrapper class (XboxCommonDVRStreaming in the case of helios)
 */
UCLASS(MinimalAPI)
class UGameplayStreamingService : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UBaseGameplayStreamingHandler> ActiveHandler;

};

