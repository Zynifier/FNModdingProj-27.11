// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_ItemVariant.generated.h"

UCLASS(Abstract)
class UAssetDefinition_ItemVariant : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UItemVariantFactory : public UFactory
{
	GENERATED_BODY()

};

