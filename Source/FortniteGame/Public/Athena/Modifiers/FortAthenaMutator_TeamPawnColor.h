// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TeamPawnColor.generated.h"

class UFortControllerComponent_TeamPawnColor;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FTeamPawnColor_VisualData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	TSubclassOf<UGameplayEffect> GE_Glow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	FGameplayTag GlowTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	FLinearColor MiniMapColor;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TeamPawnColor : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Visuals")
	TSubclassOf<UFortControllerComponent_TeamPawnColor> TeamPawnColorControllerComponentClass;

	UPROPERTY(EditAnywhere, Category="Visuals")
	TMap<uint8, FTeamPawnColor_VisualData> TeamVisualsMap;

};

