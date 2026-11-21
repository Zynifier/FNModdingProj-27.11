// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_ItemType.generated.h"

UCLASS(Abstract)
class UAssetDefinition_ItemType : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UItemTypeFactory : public UFactory
{
	GENERATED_BODY()

};

