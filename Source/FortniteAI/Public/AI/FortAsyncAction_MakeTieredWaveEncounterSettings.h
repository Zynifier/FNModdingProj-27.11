// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortEncounterSettings.h"
#include "STW/TieredWaveSet.h"
#include "FortAsyncAction_MakeTieredWaveEncounterSettings.generated.h"

class UFortAsyncAction_MakeTieredWaveEncounterSettings;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortEncounterSettingsDelegate, const FFortEncounterSettings&, EncounterSettings);

UCLASS()
class UFortAsyncAction_MakeTieredWaveEncounterSettings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_MakeTieredWaveEncounterSettings* CreateAsyncAction_MakeTieredWaveEncounterSettings(const FTieredWaveSetData& WaveData, const FFortEncounterSettings& InEncounterSettings);

	UPROPERTY(BlueprintAssignable)
	FFortEncounterSettingsDelegate OnComplete;

private:
	UPROPERTY(Transient)
	FTieredWaveSetData WaveData;

	UPROPERTY(Transient)
	FFortEncounterSettings EncounterSettings;

};

