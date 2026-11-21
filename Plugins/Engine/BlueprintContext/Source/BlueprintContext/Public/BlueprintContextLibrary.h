// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintContextLibrary.generated.h"

class UObject;
class USubsystem;

UCLASS()
class BLUEPRINTCONTEXT_API UBlueprintContextLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="BlueprintContext", meta=(BlueprintInternalUseOnly="true", WorldContext="ContextObject"))
	static USubsystem* GetContext(UObject* ContextObject, TSubclassOf<USubsystem> Class);

};

