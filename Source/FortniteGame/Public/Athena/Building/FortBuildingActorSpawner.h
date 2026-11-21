// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/Actor.h"
#include "FortBuildingActorSpawner.generated.h"

class ABuildingActor;
class UChildActorComponent;
class UEnvQuery;

UENUM()
enum class ESpawnResult : uint8
{
	Success = 0,
	Failure_NoLocationFound = 1,
	Failure_NoActorClass = 2,
	Failure_BadQueryData = 3,
};

UCLASS()
class AFortBuildingActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Class to Spawn")
	TSubclassOf<ABuildingActor> ActorClassToSpawn;

protected:
	UPROPERTY(EditAnywhere, Category="Placement")
	TObjectPtr<UEnvQuery> QueryTemplate;

	UPROPERTY(EditAnywhere, Category="Placement")
	TArray<FAIDynamicParam> QueryConfig;

	UPROPERTY(EditAnywhere, Category="Placement")
	bool bSpawnAtPreviewPositionNoQuery;

	UPROPERTY(EditAnywhere, Category="Placement")
	bool bSpawnAtPreviewRotation;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;
#endif

};

