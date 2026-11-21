// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortGameStateComponent_MidMatchObjectiveParent.h"
#include "FortGameStateComponent_AssignedObjective.generated.h"

class UEnvQuery;
class UObject;

USTRUCT(BlueprintType)
struct FFortAssignedObjectiveSquadData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAssignedObjectiveSquadData")
	uint8 SquadId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAssignedObjectiveSquadData")
	FVector CachedSquadAvgLocation;

};

USTRUCT(BlueprintType)
struct FFortAssignedObjectiveData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAssignedObjectiveData")
	TArray<FFortAssignedObjectiveSquadData> AssignedSquadDataArray;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAssignedObjectiveData")
	FVector ObjectiveLocation;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_AssignedObjective : public UFortGameStateComponent_MidMatchObjectiveParent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static FVector CalculateSquadAvgLocation(const uint8 SquadId, const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartAssignedObjectives();

	UPROPERTY(EditDefaultsOnly, Category="Objective Matchmaking")
	FScalableFloat IdealNumSquadsPerObjective;

	UPROPERTY(EditDefaultsOnly, Category="Objective Matchmaking|Unopposed Squad")
	FScalableFloat bAllowUnopposedSquads;

	UPROPERTY(EditDefaultsOnly, Category="Objective Matchmaking|Unopposed Squad")
	FScalableFloat MinPairedSquadDistForUnopposed;

	UPROPERTY(EditDefaultsOnly, Category="Objective Matchmaking|Unopposed Squad")
	FScalableFloat UnopposedSquad_FakeSquadMaxSafeZonePct;

	UPROPERTY(EditDefaultsOnly, Category="Objective Matchmaking|Unopposed Squad")
	FScalableFloat UnopposedSquad_FakeSquadMinDistToSquad;

	UPROPERTY(EditDefaultsOnly, Category="Objective Spawning", meta=(ClampMax="1.0", ClampMin="0.0"))
	FScalableFloat SpawnObjectivesInsideSafeZonePct;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAssignedObjectiveReady(UPARAM(ref) FFortAssignedObjectiveData& ObjectiveData);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameStateComponent_AssignedObjective")
	TSoftObjectPtr<UEnvQuery> AssignedObjectiveLocationEnvQuery;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameStateComponent_AssignedObjective")
	TArray<FFortAssignedObjectiveData> AssignedObjectives;

};

