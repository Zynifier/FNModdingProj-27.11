// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAILODSettingsInterfaces.h"
#include "FortAthenaAILODSettings_GenericTickingObject.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFortAILODSetting_GenericTickingObject : public FFortAthenaAILODSetting
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat TickMultiplier;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAILODSettings_GenericTickingObject : public UObject, public IFortAthenaAILODSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UObject>> SystemClasses;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject BelowLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject LowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject AboveLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject BelowNormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject NormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_GenericTickingObject AboveNormalLODSettings;

};

