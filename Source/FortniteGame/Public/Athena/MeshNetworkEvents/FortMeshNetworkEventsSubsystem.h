// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Athena/MeshNetworkEvents/FortMeshNetworkEventsLoader.h"
#include "FortMeshNetworkEventsSubsystem.generated.h"

class UFortEventResponderComponent;
enum class EMeshNetworkNodeType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMeshNetworkEventBurst, FName, EventName, EMeshNetworkNodeType, NodeType, FString, EventParameters);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnMeshNetworkEventChange, FName, EventName, FDateTime, EventStartTime, EMeshNetworkNodeType, NodeType, FString, EventParameters);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMeshNetworkEventEnd, FName, EventName, EMeshNetworkNodeType, NodeType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnMeshNetworkEventStart, FName, EventName, FDateTime, EventStartTime, EMeshNetworkNodeType, NodeType, FString, EventParameters);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMeshNetworkReady, EMeshNetworkNodeType, NodeType);

USTRUCT()
struct FEventResponderTrackingItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName EventName;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortEventResponderComponent>> EventResponders;

};

UCLASS(meta=(DisplayName="Fort Mesh Network Events"))
class UFortMeshNetworkEventsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mesh Network Events")
	bool GetActiveMeshNetworkEvent(FMeshNetworkEventStateData& OutEventData, const FName& EventName, const FGameplayTagContainer& EventFilters) const;

	UFUNCTION(BlueprintPure, Category="Mesh Network Events")
	void GetActiveMeshNetworkEvents(TArray<FMeshNetworkEventStateData>& ActiveMeshNetworkEvents) const;

	UFUNCTION(BlueprintPure, Category="Mesh Network Events")
	EMeshNetworkNodeType GetMeshNetworkNodeType() const;

	UFUNCTION(BlueprintPure, Category="Mesh Network Events")
	bool IsMeshNetworkEventActive(const FName& EventName, const FGameplayTagContainer& Filters) const;

protected:
	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventBurst OnMeshNetworkEventBurst;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventStart OnMeshNetworkEventStart;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventChange OnMeshNetworkEventChange;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventEnd OnMeshNetworkEventEnd;

	UPROPERTY()
	TArray<FEventResponderTrackingItem> EventResponderList;

};

