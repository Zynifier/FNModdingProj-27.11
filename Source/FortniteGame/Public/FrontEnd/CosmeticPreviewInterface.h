// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticPreviewInterface.generated.h"

class UFortItemDefinition;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UCosmeticPreviewInterface : public UInterface
{
	GENERATED_BODY()
};

class ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Visuals")
	void CustomizePreviewInstance(const UFortItemDefinition* InItemDefinition);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Visuals")
	void GetSpecialPreviewActions(TArray<FName>& OutActionList);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Visuals")
	void PerformSpecialAction(FName ActionName);

};

