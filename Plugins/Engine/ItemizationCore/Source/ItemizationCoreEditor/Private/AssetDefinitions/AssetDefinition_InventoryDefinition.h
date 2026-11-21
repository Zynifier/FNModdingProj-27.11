// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_InventoryDefinition.generated.h"

UCLASS(Abstract)
class UAssetDefinition_InventoryDefinition : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UInventoryDefinitionFactory : public UFactory
{
	GENERATED_BODY()

};

