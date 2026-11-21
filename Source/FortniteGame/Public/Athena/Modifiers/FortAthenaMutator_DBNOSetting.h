// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/DBNOCustomSettings.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_DBNOSetting.generated.h"

class AActor;
class AFortAthenaMutator_DBNOSetting;
class AFortMinigame;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_DBNOSetting : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static AFortAthenaMutator_DBNOSetting* GetDBNOSettingsMutator(const AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	virtual void SetDBNOSettingsAndOverride(FDBNOCustomSettings InDBNOSettings, AActor* ActorApplyingSettings);

	UFUNCTION(BlueprintCallable)
	virtual void UnsetDBNOSettings(const AActor* ActorRemovingSettings);

private:
	UPROPERTY(Transient, Replicated)
	TArray<FDBNOSettingsByActor> SettingsByActor;

};

