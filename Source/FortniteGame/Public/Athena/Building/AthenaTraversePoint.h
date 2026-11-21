// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Building/BuildingGameplayActor.h"
#include "AthenaTraversePoint.generated.h"

class AActor;
class AAthenaTraversePoint;

UENUM(BlueprintType)
enum class ETraversePointState : uint8
{
	None = 0,
	Hidden = 1,
	Active = 2,
	TouchedByPlayer = 3,
	Finished = 4,
};

USTRUCT()
struct FTraversePointSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<AAthenaTraversePoint> PointClass;

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FRotator Rotation;

};

UCLASS(MinimalAPI, HideCategories=("AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaTraversePoint : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void OnImpactedByPlayer(AActor* PlayerActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewState_Active_Client();

	UFUNCTION()
	virtual void OnNewState_Active_Server();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewState_Finished_Client();

	UFUNCTION()
	virtual void OnNewState_Finished_Server();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewState_Hidden_Client();

	UFUNCTION()
	virtual void OnNewState_Hidden_Server();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewState_TouchedByPlayer_Client();

	UFUNCTION()
	virtual void OnNewState_TouchedByPlayer_Server();

	UFUNCTION()
	virtual void OnRep_CurrentState();

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FVector2D MiniMapSize;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FVector2D CompassSize;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FSlateBrush MiniMapBrush_Active;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FSlateBrush CompassBrush_Active;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTraversePoint")
	bool bShouldTeleportToGround;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentState)
	ETraversePointState CurrentState;

};

