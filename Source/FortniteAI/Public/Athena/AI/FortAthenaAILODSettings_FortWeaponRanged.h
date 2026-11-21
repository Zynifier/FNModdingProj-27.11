// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAILODSettingsInterfaces.h"
#include "FortAthenaAILODSettings_FortWeaponRanged.generated.h"

class AFortWeaponRanged;

USTRUCT(BlueprintType)
struct FFortAILODSetting_FortWeaponRanged : public FFortAthenaAILODSetting
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat Interval;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat RandomDeviation;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAILODSettings_FortWeaponRanged : public UObject, public IFortAthenaAILODSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<AFortWeaponRanged>> SystemClasses;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged BelowLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged LowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged AboveLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged BelowNormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged NormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_FortWeaponRanged AboveNormalLODSettings;

};

