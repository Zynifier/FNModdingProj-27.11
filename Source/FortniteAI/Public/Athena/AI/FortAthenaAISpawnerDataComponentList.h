// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaAISpawnerDataComponentList.generated.h"

class APawn;
class UFortAthenaAISpawnerDataComponent;
class UFortAthenaAISpawnerDataComponentList;
class UObject;

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAISpawnerDataComponentList : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFortAthenaAISpawnerDataComponent* GetComponentClassForModification(const TSubclassOf<UFortAthenaAISpawnerDataComponent> ClassToGet);

	UFUNCTION(BlueprintPure)
	const APawn* GetDefaultPawn() const;

	UFUNCTION(BlueprintCallable)
	TArray<UFortAthenaAISpawnerDataComponent*> GetList();

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent* GetOrCreateComponentClassForModification(UObject* ComponentOuter, const TSubclassOf<UFortAthenaAISpawnerDataComponent> ClassToClone) const;

	UFUNCTION(BlueprintPure)
	const FTransform& GetSpawnTransform() const;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="TRUE"))
	UFortAthenaAISpawnerDataComponentList* OverrideComponent(const UFortAthenaAISpawnerDataComponent* NewComponent);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="TRUE"))
	UFortAthenaAISpawnerDataComponentList* OverrideComponentClass(const TSubclassOf<UFortAthenaAISpawnerDataComponent> NewComponentSubClass);

};

