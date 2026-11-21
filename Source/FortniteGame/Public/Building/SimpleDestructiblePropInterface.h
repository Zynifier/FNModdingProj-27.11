// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleDestructiblePropInterface.generated.h"

class UStaticMeshComponent;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class USimpleDestructiblePropInterface : public UInterface
{
	GENERATED_BODY()
};

class ISimpleDestructiblePropInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	void GetSimpleDestructiblePropComponents(TArray<UStaticMeshComponent*>& StaticMeshComponents);

};

