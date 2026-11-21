// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityDataBackedComponent.generated.h"

USTRUCT()
struct FComponentData
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class ENTITYCORE_API UEntityDataBackedComponent : public UEntityComponent
{
	GENERATED_BODY()

};

