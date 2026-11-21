// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_ItemAttribute.generated.h"

UCLASS(Abstract)
class UAssetDefinition_ItemAttribute : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UItemAttributeFactory : public UFactory
{
	GENERATED_BODY()

};

