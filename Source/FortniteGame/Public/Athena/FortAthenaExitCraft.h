// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortAthenaExitCraft.generated.h"

class AActor;
class AFortAthenaExitCraftBalloon;
class AFortPlayerPawnAthena;
class UCurveFloat;
class UFortAthenaExitCraftInfo;
class UMaterialInterface;
class UPhysicsConstraintComponent;
class UStaticMeshComponent;
enum class EExitCraftState : uint8;

UENUM(BlueprintType)
enum class EExitCraftState : uint8
{
	None = 0,
	Spawned = 1,
	Landed = 2,
	SpawnBalloon = 3,
	GettingIntoPosition = 4,
	GettingIntoPosition_Simple = 5,
	WaitingForPawns = 6,
	Exiting = 7,
};

USTRUCT()
struct FLocationLerpData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	FVector PositionLerp_Start;

	UPROPERTY(NotReplicated)
	FVector PositionLerp_End;

	UPROPERTY()
	FVector PositionLerp_Target;

	UPROPERTY()
	float TotalLerpTime;

};

USTRUCT()
struct FRotationLerpData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	FQuat RotationLerp_Start;

	UPROPERTY(NotReplicated)
	FQuat RotationLerp_End;

	UPROPERTY()
	FQuat RotationLerp_Target;

	UPROPERTY()
	float TotalLerpTime;

};

UCLASS(HideCategories=("Navigation"))
class AFortAthenaExitCraft : public AFortAthenaVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CheatDepart();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> OverlapMesh;

	UPROPERTY(Replicated)
	TObjectPtr<UFortAthenaExitCraftInfo> ExitCraftInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FVector GetBalloonLocation() const;

	UFUNCTION()
	void OnDepartFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoveEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoveStart();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewState(EExitCraftState NewState);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(AActor* TestActor);

	UFUNCTION(BlueprintCallable)
	void OnOverlapStart(AActor* TestActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRemakeMIDs();

	UFUNCTION()
	void OnRep_BalloonActor();

	UFUNCTION()
	void OnRep_CurrentState();

	UFUNCTION()
	void OnRep_QualifyingPlayers();

	UFUNCTION()
	void OnRep_VehicleSkinIndex();

	UPROPERTY(Transient)
	FName CraftSpecialActorID;

	UPROPERTY(EditDefaultsOnly, Transient, Replicated, Category="FortAthenaExitCraft")
	uint8 bCorrectionMade : 1;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentState)
	EExitCraftState CurrentState;

	UPROPERTY(ReplicatedUsing=OnRep_QualifyingPlayers)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> OverlappingPawns;

	UPROPERTY(EditDefaultsOnly, Category="Balloon")
	TSubclassOf<AFortAthenaExitCraftBalloon> BalloonClass;

	UPROPERTY(ReplicatedUsing=OnRep_BalloonActor)
	TObjectPtr<AFortAthenaExitCraftBalloon> BalloonActor;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TObjectPtr<UCurveFloat> GettingIntoPostionCurve_Location;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TObjectPtr<UCurveFloat> GettingIntoPostionCurve_Rotation;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	float BuildingZOffset;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer TagsToApplyOnAttached;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FText InteractText;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float SafetyTimerTime;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<TObjectPtr<UMaterialInterface>> VehicleSkins;

	UPROPERTY(ReplicatedUsing=OnRep_VehicleSkinIndex)
	int32 VehicleSkinIndex;

private:
	UFUNCTION()
	void OnRep_LocationLerpData();

	UFUNCTION()
	void OnRep_RotationLerpData();

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawnAthena>> PlayersNeedingSeats;

	UPROPERTY(ReplicatedUsing=OnRep_LocationLerpData)
	FLocationLerpData LocationLerpData;

	UPROPERTY(ReplicatedUsing=OnRep_RotationLerpData)
	FRotationLerpData RotationLerpData;

};

UCLASS()
class AFortAthenaExitCraftBalloon : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RootMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UPhysicsConstraintComponent> PhysicsComp;

};

