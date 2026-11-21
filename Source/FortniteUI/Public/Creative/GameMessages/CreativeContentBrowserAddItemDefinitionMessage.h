// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeContentBrowserAddItemDefinitionMessage.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FORTNITEUI_API FCreativeContentBrowserAddItemDefinitionMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefinitionsToAdd;

};

