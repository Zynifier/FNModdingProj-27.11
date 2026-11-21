// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MeshNetworkTypes.h"
#include "MeshNetworkComponent.generated.h"

class UObject;
enum class EMeshNetworkNodeType : uint8;

USTRUCT()
struct FAggregatedFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UObject> Function;

};

USTRUCT(meta=(Category="Mesh Networking"))
struct FAggregatedFunctionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="AggregatedFunctionConfig")
	double AggregationTimeout;

	UPROPERTY(VisibleAnywhere, Category="AggregatedFunctionConfig")
	bool bAggregationEnabled;

	UPROPERTY(VisibleAnywhere, Category="AggregatedFunctionConfig")
	TSet<FName> NoAggregationParameters;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class MESHNETWORK_API UMeshNetworkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mesh Networking")
	EMeshNetworkNodeType GetMeshNetworkNodeType() const;

	UFUNCTION(BlueprintPure, Category="Mesh Networking")
	bool IsConnectedToMeshRoot() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh Networking")
	EMeshNetworkRelevancy MeshRelevancy;

private:
	UPROPERTY(Transient)
	TMap<FString, FAggregatedFunction> AggregatedFunctions;

	UPROPERTY(VisibleAnywhere, Category="Mesh Networking")
	TMap<FName, FAggregatedFunctionConfig> AggregatedFunctionConfigs;

};

