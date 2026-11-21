// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeContentBrowserRemoveItemDefinitionMessage.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FORTNITEUI_API FCreativeContentBrowserRemoveItemDefinitionMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefinitionsToRemove;

};

