// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FGF_GameState.h"
#include "FortGameStateBase.generated.h"

class IFortTimeOfDayManagerInterface;

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateBase : public AFGF_GameState
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="TimeOfDay")
	TScriptInterface<IFortTimeOfDayManagerInterface> GetTimeOfDayManager() const;

protected:
	UFUNCTION()
	void OnRep_TimeOfDayManager();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TimeOfDayManager)
	TScriptInterface<IFortTimeOfDayManagerInterface> FortTimeOfDayManager;

};

