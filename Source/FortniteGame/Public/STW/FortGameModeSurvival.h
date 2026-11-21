// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/FortGameModePvE.h"
#include "FortGameModeSurvival.generated.h"

class ABuildingActor;
enum class EFortReportDayPhase : uint8;

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeSurvival : public AFortGameModePvE
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Analytics")
	void FireEvent_SurvivalPeriodicReport(EFortReportDayPhase TimeOfReport, const TArray<ABuildingActor*>& ActorsBeingDefended) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Analytics")
	void FireEvent_SurvivalVoteReport(const TArray<ABuildingActor*>& ActorsBeingDefended) const;

};

