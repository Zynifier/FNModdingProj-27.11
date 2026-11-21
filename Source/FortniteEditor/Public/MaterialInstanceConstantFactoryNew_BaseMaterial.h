// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "MaterialInstanceConstantFactoryNew_BaseMaterial.generated.h"

UCLASS(HideCategories=("Object", "Object"))
class UMaterialInstanceConstantFactoryNew_BaseMaterial : public UMaterialInstanceConstantFactoryNew
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BaseMaterial")
	FString BaseMaterialName;

};

