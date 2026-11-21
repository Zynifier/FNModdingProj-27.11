// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClamberingTypes.h"
#include "ClamberingLibrary.generated.h"

class ACharacter;

UCLASS(meta=(ScriptName="ClamberingLibrary"))
class UClamberingLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Clambering")
	static bool PerformClamberingTargeting(const ACharacter* Character, FClamberingTargetingData& OutTargetingData);

};

