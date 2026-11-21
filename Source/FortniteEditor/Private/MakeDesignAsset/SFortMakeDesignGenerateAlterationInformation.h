// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SFortMakeDesignGenerateAlterationInformation.generated.h"

class UFortSchematicItemDefinition;

UENUM()
enum class EAlterationSelectionMode : uint8
{
	Single = 0,
	Batch = 1,
};

USTRUCT()
struct FGenerateAlterationInfoDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Input")
	TSoftObjectPtr<UFortSchematicItemDefinition> Schematic;

};

