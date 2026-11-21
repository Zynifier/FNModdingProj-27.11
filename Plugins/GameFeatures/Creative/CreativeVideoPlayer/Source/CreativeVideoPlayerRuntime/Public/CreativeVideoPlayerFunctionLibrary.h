// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CreativeVideoPlayerFunctionLibrary.generated.h"

class AController;

UCLASS()
class CREATIVEVIDEOPLAYERRUNTIME_API UCreativeVideoPlayerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void ShutdownFullscreenVideoMode(AController* Controller);

};

