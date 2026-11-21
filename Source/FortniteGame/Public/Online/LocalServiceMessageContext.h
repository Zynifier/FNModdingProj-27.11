// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "LocalServiceMessageContext.generated.h"

UCLASS(MinimalAPI)
class ULocalServiceMessageContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddLocalServiceMessage(const FString& Identifier, FText Title, FText Body);

	UFUNCTION(BlueprintCallable)
	void RemoveLocalServiceMessage(const FString& Identifier);

};

