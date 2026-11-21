// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortSpatialGameplayLibrary.generated.h"

class AActor;
class IFortSpatialGameplayInterface;
class UActorComponent;

UCLASS(MinimalAPI, meta=(ScriptName="SpatialGameplayLibrary"))
class UFortSpatialGameplayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SpatialGameplay", meta=(DeterminesOutputType="ComponentType", DynamicOutputParam="OutComponents"))
	static bool GetComponentsFromSpatialGameplayInterfaceByClass(const TScriptInterface<IFortSpatialGameplayInterface>& SpatialGameplayInterface, const TSubclassOf<UActorComponent> ComponentType, TArray<UActorComponent*>& OutComponents);

	UFUNCTION(BlueprintPure, Category="SpatialGameplay")
	static FName GetSpatialGameplayInterfaceFNameForActor(const AActor* Actor);

};

