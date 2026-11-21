// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortWidgetComponent.h"
#include "FortTamedNpcWidgetComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Mobility", "Trigger"))
class UFortTamedNpcWidgetComponent : public UFortWidgetComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	float VerticalOffsetToHealthBar;

private:
	UFUNCTION()
	void HandleOnHideIndicator();

	UFUNCTION()
	void HandleOnShowIndicator(bool bCanShowIndicator);

};

