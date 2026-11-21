// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Factories/Factory.h"
#include "AssetDefinition_EquippableInventoryDefinition.generated.h"

UCLASS(Abstract)
class UAssetDefinition_EquippableInventoryDefinition : public UAssetDefinitionDefault
{
	GENERATED_BODY()

};

UCLASS()
class UAssetDefinition_EquipmentHotBar : public UAssetDefinition_EquippableInventoryDefinition
{
	GENERATED_BODY()

};

UCLASS()
class UAssetDefinition_EquipmentSlot : public UAssetDefinition_EquippableInventoryDefinition
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UEquippableInventoryDefinitionFactory : public UFactory
{
	GENERATED_BODY()

};

UCLASS()
class UEquipmentHotBarDefinitionFactory : public UEquippableInventoryDefinitionFactory
{
	GENERATED_BODY()

};

UCLASS()
class UEquipmentSlotDefinitionFactory : public UEquippableInventoryDefinitionFactory
{
	GENERATED_BODY()

};

