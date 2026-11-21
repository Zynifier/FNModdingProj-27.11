// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLinkedAnimLayerInterface.generated.h"

class UAnimInstance;

UINTERFACE(BlueprintType)
class UFortLinkedAnimLayerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortLinkedAnimLayerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Linked Animation Layers")
	TSubclassOf<UAnimInstance> GetAssociatedLinkedAnimLayerClass() const;

};

