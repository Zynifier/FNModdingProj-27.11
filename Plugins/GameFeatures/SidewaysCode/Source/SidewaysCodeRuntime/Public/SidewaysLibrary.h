// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SidewaysLibrary.generated.h"

class AActor;
class USidewaysStateComponent;

UCLASS(meta=(ScriptName="SidewaysLibrary"))
class SIDEWAYSCODERUNTIME_API USidewaysLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sideways")
	static USidewaysStateComponent* GetSidewaysStateComponent(const AActor* Owner);

};

