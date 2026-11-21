// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AthenaAIBudgetManagerTypes.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_LODBase.h"
#include "FortAthenaAISpawnerDataComponent_LOD.generated.h"

class UFortAthenaAILODSettingsContainer;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_LOD : public UFortAthenaAISpawnerDataComponent_LODBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAILODSettingsContainer> LODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	FClientAILODSettings ClientLODSettings;

};

