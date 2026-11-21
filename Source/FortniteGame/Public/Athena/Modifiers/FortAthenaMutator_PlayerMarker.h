// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PlayerMarker.generated.h"

class AFortPlayerStateAthena;
class UGameplayEffect;

USTRUCT()
struct FPlayerMarkerMutatorEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> MarkedPlayerState;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerMarker : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PlayerMarker")
	TSubclassOf<UGameplayEffect> PlayerMarkerMarkerEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaMutator_PlayerMarker")
	FScalableFloat MaxTeamAliveCountForMarker;

private:
	UPROPERTY(Replicated)
	TArray<FPlayerMarkerMutatorEffectData> PlayerMarkerEffectDataArray;

};

