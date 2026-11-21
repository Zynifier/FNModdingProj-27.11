// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_TODOverride.h"
#include "FortAthenaMutator_FogSettings.generated.h"

enum class EAthenaFogDensityOverride : uint8;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_FogSettings : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FLinearColor GetFogColorOverride() const;

	UFUNCTION(BlueprintPure)
	EAthenaFogDensityOverride GetFogDensityOverride() const;

	UFUNCTION(BlueprintPure)
	static float GetFogDensityValue(const EAthenaFogDensityOverride FogDensityOverride);

	UFUNCTION(BlueprintCallable)
	void SetFogColorIndexOverride(FLinearColor NewValue);

	UFUNCTION(BlueprintCallable)
	void SetFogDensityOverride(EAthenaFogDensityOverride NewValue);

	UFUNCTION(BlueprintCallable)
	void UnsetFogOverrides();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fog")
	EAthenaFogDensityOverride FogDensityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fog")
	FLinearColor FogColor;

};

