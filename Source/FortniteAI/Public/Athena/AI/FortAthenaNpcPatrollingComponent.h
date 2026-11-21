// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Athena/AI/FortAthenaAIObjectTracker.h"
#include "FortAthenaNpcPatrollingComponent.generated.h"

class AAIController;
class AFortAthenaPatrolPath;
class AFortAthenaPatrolPoint;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPatrollingComponentOnStartPatrolling);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPatrollingComponentOnStopPatrolling);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAthenaNpcPatrollingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool FindAndSetDynamicPatrolPath(const FFortAthenaAIObjectTrackerQuery& FindQuery, const bool bOrientationAlreadyRandomized = false, const bool bExcludeCurrentlyUsedPatrolPath = true);

	UFUNCTION(BlueprintPure)
	AFortAthenaPatrolPoint* GetCurrentPatrolPoint() const;

	UFUNCTION(BlueprintPure)
	const AFortAthenaPatrolPath* GetPatrolPath() const;

	UFUNCTION(BlueprintPure)
	int32 GetPatrolPointsCount() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentPatrolPointAnEndPoint() const;

	UFUNCTION(BlueprintPure)
	bool IsPatrollingEnable() const;

	UFUNCTION(BlueprintCallable)
	void RemovePatrolPath();

	UFUNCTION(BlueprintCallable)
	void SelectNextPatrolPoint();

	UFUNCTION(BlueprintCallable)
	void SetPatrolPath(AFortAthenaPatrolPath* NewPatrolPath, const bool bOrientationAlreadyRandomized = false);

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentDestinationToNearestNextPoint();

private:
	UFUNCTION()
	void OnPatrolPathStatusChanged(const bool bEnableState);

	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedAIController;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FPatrollingComponentOnStartPatrolling OnStartPatrollingEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FPatrollingComponentOnStopPatrolling OnStopPatrollingEvent;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaPatrolPath> PatrolPath;

};

