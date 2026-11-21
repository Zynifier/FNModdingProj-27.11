// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortMeshNetworkEventsLoader.generated.h"

class AFortMeshNetworkEventsLoader;
enum class EMeshNetworkNodeType : uint8;

USTRUCT(BlueprintType)
struct FMeshNetworkEventStateData : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MeshNetworkEventStateData")
	FName EventName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MeshNetworkEventStateData")
	FDateTime EventStartTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MeshNetworkEventStateData")
	FString EventParameters;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MeshNetworkEventStateData")
	FGameplayTagContainer EventFilters;

};

USTRUCT()
struct FMeshNetworkEventStateDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AFortMeshNetworkEventsLoader> OwningLoader;

protected:
	UPROPERTY(Transient)
	TArray<FMeshNetworkEventStateData> StateData;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Collision", "Input", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortMeshNetworkEventsLoader : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastMeshNetEventBurst(FName EventName, const FString& EventParams, const FGameplayTagContainer& Filters);

protected:
	UFUNCTION()
	void OnMeshNetworkReady(EMeshNetworkNodeType NodeType);

	UPROPERTY(Transient)
	bool bMeshNetworkReady;

	UPROPERTY(Transient, Replicated)
	FMeshNetworkEventStateDataArray ActiveMeshNetworkEvents;

};

