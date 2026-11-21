// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInitializeFromObjectInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortInitializeFromObjectInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortInitializeFromObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Init")
	void InitFromObject(UObject* InitObject);

};

