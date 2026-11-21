// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_IsWorldResourceWidgetVisible.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_IsWorldResourceWidgetVisible : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_bGoldCurrencyResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bMetalResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bStoneResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bWoodResourceWidgetVisible();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_bWoodResourceWidgetVisible, Category="Is World Resource Widget Visible")
	bool bWoodResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_bStoneResourceWidgetVisible, Category="Is World Resource Widget Visible")
	bool bStoneResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_bMetalResourceWidgetVisible, Category="Is World Resource Widget Visible")
	bool bMetalResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_bGoldCurrencyResourceWidgetVisible, Category="Is World Resource Widget Visible")
	bool bGoldCurrencyResourceWidgetVisible;

};

