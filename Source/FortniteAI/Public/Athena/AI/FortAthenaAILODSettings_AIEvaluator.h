// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAILODSettingsInterfaces.h"
#include "FortAthenaAILODSettings_AIEvaluator.generated.h"

class UFortAthenaAIEvaluator;

USTRUCT(BlueprintType)
struct FFortAILODSetting_AIEvaluator : public FFortAthenaAILODSetting
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat IntervalMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat RandomDeviationMultiplier;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAILODSettings_AIEvaluator : public UObject, public IFortAthenaAILODSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortAthenaAIEvaluator>> SystemClasses;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator BelowLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator LowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator AboveLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator BelowNormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator NormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_AIEvaluator AboveNormalLODSettings;

};

