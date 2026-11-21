// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "StateTreeInstanceData.h"
#include "StateTreeManagerComponent.generated.h"

class UObject;
class UStateTree;
class UStateTreeManagerComponent;
class UStateTreeTaskObject;

UENUM()
enum class ETaskObjectStateChangeType : uint8
{
	None = 0,
	BeginState = 1,
	EndState = 2,
};

USTRUCT(BlueprintType)
struct FActorOwnedStateTreeConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ActorOwnedStateTreeConfig")
	TSoftObjectPtr<UStateTree> StateTreeAsset;

	UPROPERTY(EditAnywhere, Category="ActorOwnedStateTreeConfig")
	bool bShouldReplicate;

};

USTRUCT()
struct FStateChangeData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 StateTreeDataHandle;

	UPROPERTY()
	int32 Handle;

	UPROPERTY()
	int32 StateIdentifier;

	UPROPERTY()
	TObjectPtr<UStateTreeTaskObject> StateObject;

	UPROPERTY()
	ETaskObjectStateChangeType StateChangeType;

};

USTRUCT()
struct FStateChangeDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FStateChangeData> StateChangeDataList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStateTreeManagerComponent> StateTreeManagerComponent;

};

USTRUCT()
struct FStateTreeClientSimulationData
{
	GENERATED_BODY()

};

USTRUCT()
struct FStateTreeRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> Owner;

	UPROPERTY()
	TObjectPtr<UStateTree> StateTree;

	UPROPERTY()
	FStateTreeInstanceData StateTreeInstanceData;

};

UCLASS(MinimalAPI)
class UStateTreeManagerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FStateTreeRuntimeData> StateTreeRuntimeDataList;

	UPROPERTY(Transient)
	TArray<FStateTreeClientSimulationData> SimulatedDataList;

	UPROPERTY(Transient, Replicated)
	FStateChangeDataArray ReplicatedStateChanges;

};

