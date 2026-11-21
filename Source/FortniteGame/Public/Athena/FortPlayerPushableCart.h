// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "FortPlayerPushableCart.generated.h"

class AActor;
class AFortAthenaMutator_Uranium;
class AFortPlayerPawn;
class UFortMovementComp_GroundSpline;
class UShapeComponent;
class USplineComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerPushableCartOnTeamsRolesChanged, uint8, PusherTeam, uint8, DefenderTeam);

USTRUCT()
struct FTeamRoles
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 PusherTeam;

	UPROPERTY()
	uint8 DefenderTeam;

};

UCLASS(BlueprintType, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortPlayerPushableCart : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCartApproachingCheckPoint);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCartPlayerPushableChanged, bool, bNewPlayerPushable);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCheckPointReached, int32, CheckPointIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerEnteredPushArea, AFortPlayerPawn*, PlayerState, bool, bPlayerIsAPusher);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerExitedPushArea, AFortPlayerPawn*, PlayerState, bool, bPlayerIsAPusher);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPushersOrDefendersChanged);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddPlayerToPushArea(AFortPlayerPawn* PlayerToAdd);

	UFUNCTION(BlueprintNativeEvent)
	AActor* GetCameraActor();

	UFUNCTION(BlueprintPure)
	float GetCartDistanceAlongSpline() const;

	UFUNCTION(BlueprintPure)
	void GetCheckPointTransforms(TArray<FTransform>& OutTransforms) const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefenderTeam() const;

	UFUNCTION(BlueprintPure)
	float GetDesiredSpeed() const;

	UFUNCTION(BlueprintPure)
	float GetDistanceToNextCheckPoint() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPlayerPushable() const;

	UFUNCTION(BlueprintPure)
	uint8 GetLastReachedCheckPointIndex() const;

	UFUNCTION(BlueprintPure)
	uint8 GetNextCheckPointIndex() const;

	UFUNCTION(BlueprintPure)
	float GetPercentProgressTowardsNextCheckPoint() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	UShapeComponent* GetPushAreaShapeComponent() const;

	UFUNCTION(BlueprintPure)
	uint8 GetPusherTeam() const;

	UFUNCTION(BlueprintPure)
	int32 GetPushingStrength() const;

	UFUNCTION(BlueprintPure)
	float GetSplineDistanceAtCheckPoint(int32 CheckPointIndex) const;

	UFUNCTION(BlueprintPure)
	int32 GetSplineIndexForCurrentCheckPoint() const;

	UFUNCTION(BlueprintPure)
	int32 GetSplineIndexForNextCheckPoint() const;

	UFUNCTION(BlueprintPure)
	uint8 GetTotalActiveDefenders() const;

	UFUNCTION(BlueprintPure)
	uint8 GetTotalActivePushers() const;

	UFUNCTION(BlueprintPure)
	int32 GetTotalCheckPoints() const;

	UFUNCTION(BlueprintPure)
	void GetTransformAtCheckPoint(FTransform& OutTransform, int32 CheckPointIndex) const;

	UFUNCTION(BlueprintPure)
	bool IsCartContested() const;

	UFUNCTION()
	bool IsNearCheckpoint();

	UFUNCTION()
	void OnSplinePointReached(int32 SplinePointReached, bool bWasMovingForward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSplineSet();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemovePlayerFromPushArea(AFortPlayerPawn* PlayerToRemove);

	UFUNCTION()
	void SetNearCheckpoint(bool bNear);

	UPROPERTY(BlueprintAssignable)
	FOnCheckPointReached OnCheckPointReached;

	UPROPERTY(BlueprintAssignable)
	FOnPushersOrDefendersChanged OnPushersOrDefendersChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCartPlayerPushableChanged OnCartPlayerPushableChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerEnteredPushArea OnPlayerEnteredPushArea;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerExitedPushArea OnPlayerExitedPushArea;

	UPROPERTY(BlueprintAssignable)
	FOnCartApproachingCheckPoint OnCartApproachingCheckPoint;

	UPROPERTY(BlueprintAssignable)
	FPlayerPushableCartOnTeamsRolesChanged PlayerPushableCartOnTeamsRolesChanged;

protected:
	UFUNCTION()
	void OnRep_bIsNearCheckpoint();

	UFUNCTION()
	void OnRep_CurrentCheckpoint();

	UFUNCTION()
	void OnRep_TeamRoles();

	UFUNCTION()
	void OnRep_TotalActiveDefenders();

	UFUNCTION()
	void OnRep_TotalActivePushers();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export, Category="FortPlayerPushableCart", meta=(EditInline="true"))
	TObjectPtr<UFortMovementComp_GroundSpline> MovementComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortPlayerPushableCart")
	TWeakObjectPtr<AFortAthenaMutator_Uranium> UraniumMutatorOwner;

	UPROPERTY(Replicated, Export)
	TWeakObjectPtr<USplineComponent> SplineComponent;

	UPROPERTY(Replicated)
	TArray<int32> SplineCheckPointIndices;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentCheckpoint)
	uint8 CurrentCheckPoint;

	UPROPERTY(ReplicatedUsing=OnRep_TeamRoles)
	FTeamRoles TeamRoles;

	UPROPERTY(ReplicatedUsing=OnRep_TotalActivePushers)
	uint8 TotalActivePushers;

	UPROPERTY(ReplicatedUsing=OnRep_TotalActiveDefenders)
	uint8 TotalActiveDefenders;

	UPROPERTY(Replicated)
	bool bIsPushable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerPushableCart")
	FScalableFloat BasePushSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerPushableCart")
	FScalableFloat PushSpeedPercentPerPusher;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerPushableCart")
	FScalableFloat Acceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerPushableCart")
	FScalableFloat Deceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerPushableCart")
	FScalableFloat YawSpeed;

	UPROPERTY(ReplicatedUsing=OnRep_bIsNearCheckpoint)
	bool bIsNearCheckpoint;

};

