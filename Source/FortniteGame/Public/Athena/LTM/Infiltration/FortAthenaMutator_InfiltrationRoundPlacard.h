// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_ShowPlacard.h"
#include "Athena/Modifiers/Interfaces/InfiltrationRoundInfoMutatorInterface.h"
#include "FortAthenaMutator_InfiltrationRoundPlacard.generated.h"

class UObject;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InfiltrationRoundPlacard : public AFortAthenaMutator_ShowPlacard, public IInfiltrationRoundInfoMutatorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_RoundInfoInterfaceRedirectReplicationObject();

	UPROPERTY(ReplicatedUsing=OnRep_RoundInfoInterfaceRedirectReplicationObject)
	TObjectPtr<UObject> RoundInfoInterfaceRedirectReplicationObject;

};

