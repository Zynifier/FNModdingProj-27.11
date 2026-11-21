// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_ItemDefinition.generated.h"

UCLASS(Abstract)
class UAssetDefinition_ItemDefinition : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UItemDefinitionFactory : public UFactory
{
	GENERATED_BODY()

};

