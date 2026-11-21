// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MeshNetworkTypes.h"
#include "MeshNetworkSubsystem.generated.h"

class AActor;
class APlayerController;
class UMeshNetworkComponent;
enum class EMeshNetworkNodeType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectedToRootChanged, bool, bConnected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameServerNodeTypeChanged, EMeshNetworkNodeType, NodeType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMeshMetaDataUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMeshNodeTypeChanged, EMeshNetworkNodeType, NodeType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMeshPlayerRequested, APlayerController*, Player, FName, Tag);

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FMeshMetaDataStruct
{
	GENERATED_BODY()

};

UCLASS(meta=(DisplayName="Mesh Network"))
class MESHNETWORK_API UMeshNetworkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MeshNetworkSubsystem")
	void DisableMeshReplication(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="MeshNetworkSubsystem")
	void EnableMeshReplication(AActor* Actor, TSubclassOf<UMeshNetworkComponent> MeshComponentClass);

	UFUNCTION(BlueprintPure, Category="MeshNetworkSubsystem")
	bool GetConnectedToRoot() const;

	UFUNCTION(BlueprintPure, Category="MeshNetworkSubsystem")
	EMeshNetworkNodeType GetGameServerNodeType() const;

	UFUNCTION(BlueprintPure, Category="MeshNetworkSubsystem")
	EMeshNetworkNodeType GetMeshNetworkNodeType() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MeshNetworkSubsystem", meta=(CustomStructureParam="MetaData", DeprecatedFunction, DeprecationMessage="Please use GetMetaDataWithKey"))
	void GetMetaData(UPARAM(ref) FMeshMetaDataStruct& MetaData);

	UFUNCTION(CustomThunk, BlueprintCallable, BlueprintAuthorityOnly, Category="MeshNetworkSubsystem", meta=(CustomStructureParam="MetaData"))
	bool GetMetaDataWithKey(FName Key, UPARAM(ref) FMeshMetaDataStruct& MetaData);
	DECLARE_FUNCTION(execGetMetaDataWithKey);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MeshNetworkSubsystem", meta=(CustomStructureParam="MetaData", DeprecatedFunction, DeprecationMessage="Please use SetMetaDataFromKey"))
	void SetMetaData(const FMeshMetaDataStruct& MetaData);

	UFUNCTION(CustomThunk, BlueprintCallable, BlueprintAuthorityOnly, Category="MeshNetworkSubsystem", meta=(CustomStructureParam="MetaData"))
	void SetMetaDataWithKey(FName Key, const FMeshMetaDataStruct& MetaData);
	DECLARE_FUNCTION(execSetMetaDataWithKey);

	UPROPERTY(BlueprintAssignable, Category="MeshNetworkSubsystem")
	FOnMeshNodeTypeChanged OnMeshNodeTypeChanged;

	UPROPERTY(BlueprintAssignable, Category="MeshNetworkSubsystem")
	FOnConnectedToRootChanged OnConnectedToRootChanged;

	UPROPERTY(BlueprintAssignable, Category="MeshNetworkSubsystem")
	FOnGameServerNodeTypeChanged OnGameServerNodeTypeChanged;

	UPROPERTY(BlueprintAssignable, Category="MeshNetworkSubsystem")
	FOnMeshMetaDataUpdated OnMeshMetaDataUpdated;

	UPROPERTY(BlueprintAssignable, Category="MeshNetworkSubsystem")
	FOnMeshPlayerRequested OnMeshPlayerRequested;

protected:
	UPROPERTY(Transient)
	EMeshNetworkNodeType NodeType;

	UPROPERTY(Transient)
	EMeshNetworkNodeType GameServerNodeType;

	UPROPERTY(Transient)
	bool bConnectedToRoot;

	UPROPERTY(Transient)
	bool bMetadataReceived;

};

