// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IQuestDefinitionInterface.generated.h"

UINTERFACE(MinimalAPI, NotBlueprintable)
class UQuestDefinitionInterface : public UInterface
{
	GENERATED_BODY()
};

class IQuestDefinitionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual FString GetQuestID() const;

};

