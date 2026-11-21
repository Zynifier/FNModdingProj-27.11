// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_MeshNetworkReady.generated.h"

class UFortAsyncAction_MeshNetworkReady;
class UObject;
enum class EMeshNetworkNodeType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMeshNetworkReadyAsyncDelegate, EMeshNetworkNodeType, NodeType);

UCLASS()
class UFortAsyncAction_MeshNetworkReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_MeshNetworkReady* MeshNetworkReadyAsync(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FMeshNetworkReadyAsyncDelegate OnReady;

private:
	UFUNCTION()
	void HandleMeshNetworkTypeSet(EMeshNetworkNodeType NodeType);

};

