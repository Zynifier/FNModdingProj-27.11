// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DagwoodNetworkPhysicsSystem.h"
#include "FortDagwoodState.h"
#include "FortDagwoodVehicle.h"
#include "DagwoodNetworkPhysics.generated.h"

class APlayerController;

USTRUCT()
struct FDagwoodFutureClientInput
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Frame;

	UPROPERTY()
	FFortDagwoodCmd InputCmd;

};

USTRUCT(BlueprintType)
struct FDagwoodState_PT
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDagwoodInternal Internal;

	UPROPERTY()
	FDagwoodOutPersistent OutPersistent;

	UPROPERTY(NotReplicated)
	FDagwoodOutContinuous OutContinuous;

	UPROPERTY()
	bool bOutValid;

};

USTRUCT(BlueprintType)
struct FDagwoodManagedState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Frame;

	UPROPERTY()
	FFortDagwoodCmd InputCmd;

	UPROPERTY()
	FDagwoodInPersistent GT_State;

	UPROPERTY()
	FDagwoodState_PT PT_State;

	UPROPERTY(NotReplicated)
	TObjectPtr<APlayerController> PC;

	UPROPERTY(NotReplicated)
	TArray<FDagwoodFutureClientInput> FutureInputs;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UDagwoodNetworkPhysicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGeneratedLocalInputCmd);

public:
	UFUNCTION(Category="Dagwood Input")
	FFortDagwoodCmd GetPendingInputCmd() const;

	UFUNCTION(Category="Dagwood State")
	FDagwoodInPersistent GetState_GT() const;

	UFUNCTION(BlueprintPure, Category="Dagwood Input")
	FDagwoodState_PT GetState_PT() const;

	UFUNCTION(Category="Dagwood Input")
	void SetPendingInputCmd(const FFortDagwoodCmd& In);

	UFUNCTION(Category="Dagwood State")
	void SetState_GT(const FDagwoodInPersistent& In);

	UPROPERTY(Transient, Replicated)
	FNetworkPhysicsState NetworkPhysicsState;

	UPROPERTY(BlueprintAssignable, Category="Components|Activation")
	FOnGeneratedLocalInputCmd OnGeneratedLocalInputCmd;

protected:
	UPROPERTY(Transient, Replicated)
	FDagwoodManagedState ReplicatedManagedState;

	UPROPERTY(Transient)
	FDagwoodManagedState InManagedState;

	UPROPERTY(Transient)
	FDagwoodManagedState OutManagedState;

};

