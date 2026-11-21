// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "NavAreas/NavAreaMeta.h"
#include "FortMetaNavArea.generated.h"

USTRUCT()
struct FNavAgentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Agents")
	FName AgentName;

	UPROPERTY(EditDefaultsOnly, Category="Agents")
	FCurveTableRowHandle BuildingActorHealthToNavAreaStrengthHandle;

	UPROPERTY(EditDefaultsOnly, Category="Agents")
	FCurveTableRowHandle PlayerBuiltBuildingActorHealthToNavAreaStrengthHandle;

};

UCLASS(BlueprintType, Blueprintable)
class UFortMetaNavArea : public UNavAreaMeta
{
	GENERATED_BODY()

public:
	UFortMetaNavArea(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditDefaultsOnly, Category="Agents")
	TArray<FNavAgentData> AgentData;

};

