// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AthenaAIBudgetManagerTypes.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_LODBase.generated.h"

class UFortAthenaAILODSettingsContainer;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_LODBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFortAthenaAILODSettingsContainer* GetAILODSettingsContainer() const;

	UFUNCTION(BlueprintNativeEvent)
	FClientAILODSettings GetClientAILODSettings() const;

};

