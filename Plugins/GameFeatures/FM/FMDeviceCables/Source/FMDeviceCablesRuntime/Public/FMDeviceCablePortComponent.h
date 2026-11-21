// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Misc/Guid.h"
#include "FMDeviceCableTypes.h"
#include "FabricInteractableInterface.h"
#include "FortLevelDuplicatableInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FMDeviceCablePortComponent.generated.h"

class AActor;
class AFMDeviceCable;
class AFortPlayerPawn;
class APlayerController;
class UFMDeviceCableAnimatorBase;
class UFMDeviceCableConnectionBase;
class UFMDeviceCableManagerComponent;
class UFMDeviceCablePortComponent;
class UFabricFloatProviderBase;
class UStaticMesh;
enum class EDeviceCableActivatedState : uint8;
enum class EDeviceCablePortAnimationSyncType : uint8;
enum class EDeviceCablePortDataType : uint8;
enum class EDeviceCablePortFlowType : uint8;
enum class EDeviceCablePortSelectableState : uint8;
enum class EPortSelectStatus : uint8;

UENUM(BlueprintType)
enum class EDeviceCableLoadableState : uint8
{
	Loadable = 0,
	NotLoadable = 1,
};

UENUM(BlueprintType)
enum class EDeviceCablePortAnimationSyncType : uint8
{
	Follower = 0,
	Authority = 1,
	Independent = 2,
};

UENUM(BlueprintType)
enum class EDeviceCablePortSelectableState : uint8
{
	Selectable = 0,
	Unselectable = 1,
};

UENUM(BlueprintType)
enum class EFMDeviceCablePortComponentAllowMultipleConnections : uint8
{
	NoPreference = 0,
	// Default, will use the default logic defined in the Device Cable Port Component to decide

	ForceMultiple = 1,
	// Force, multiple ports are allowed explicitly

	ForceSingle = 2,
};

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Harmonix"))
class FMDEVICECABLESRUNTIME_API UFMDeviceCablePortComponent : public UStaticMeshComponent, public ILevelSaveSpawnable, public ILevelDuplicatable, public IFabricInteractable
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFabricCablePortSizeUpdated, float, Size);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimatorCreated, UFMDeviceCableAnimatorBase*, Animator);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnected, UFMDeviceCablePortComponent*, ConnectedPort);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConnectedWithSourcePort, UFMDeviceCablePortComponent*, SourcePort, UFMDeviceCablePortComponent*, OtherPort);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectionEnded, UFMDeviceCableConnectionBase*, EndedConnection);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectionStarted, UFMDeviceCableConnectionBase*, NewConnection);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDisconnected, UFMDeviceCablePortComponent*, DisconnectedPort);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDisconnectFloatProvider, UFabricFloatProviderBase*, FloatProvider);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPortArtifactUpdated);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReceiveFloatProviders, const TArray<UFabricFloatProviderBase*>&, FloatProviders);

public:
	UFUNCTION(BlueprintCallable)
	void EndConnectionWithPort(UFMDeviceCablePortComponent* OtherPort);

	UFUNCTION(BlueprintPure)
	EDeviceCablePortAnimationSyncType GetAnimationSyncType() const;

	UFUNCTION(BlueprintPure)
	const FFMDeviceCableArtifact& GetCachedArtifact() const;

	UFUNCTION(BlueprintPure)
	const TArray<UFMDeviceCablePortComponent*>& GetConnectedPorts() const;

	UFUNCTION(BlueprintPure)
	const TArray<UFMDeviceCableConnectionBase*>& GetConnections() const;

	UFUNCTION(BlueprintPure)
	AFMDeviceCable* GetConstantCable();

	UFUNCTION(BlueprintCallable)
	UFMDeviceCableAnimatorBase* GetDeviceCableAnimator();

	UFUNCTION(BlueprintPure)
	FGuid GetGuid();

	UFUNCTION(BlueprintPure)
	bool GetIsPlayerPort() const;

	UFUNCTION(BlueprintPure)
	bool GetIsTerminalPort(EDeviceCablePortFlowType FlowType) const;

	UFUNCTION(BlueprintPure)
	TArray<UFMDeviceCablePortComponent*> GetNextPortsInConnections() const;

	UFUNCTION(BlueprintPure)
	const TArray<UFMDeviceCablePortComponent*>& GetOtherPortsOnActor() const;

	UFUNCTION(BlueprintPure)
	EDeviceCableActivatedState GetPortActivatedState() const;

	UFUNCTION(BlueprintPure)
	EDeviceCablePortDataType GetPortDataType() const;

	UFUNCTION(BlueprintPure)
	EDeviceCablePortFlowType GetPortFlowType() const;

	UFUNCTION(BlueprintPure)
	EDeviceCablePortSelectableState GetPortSelectableState() const;

	UFUNCTION(BlueprintPure)
	TArray<UFMDeviceCablePortComponent*> GetPreviousPortsInConnections() const;

	UFUNCTION(BlueprintPure)
	bool IsConnected() const;

	UFUNCTION(BlueprintPure)
	bool IsConnectedToPort(UFMDeviceCablePortComponent* Port) const;

	UFUNCTION(BlueprintPure)
	bool MatchesPortConnectionType(UFMDeviceCablePortComponent* OtherPort) const;

	UFUNCTION(BlueprintCallable)
	void OpenConnectionToPort(UFMDeviceCablePortComponent* OtherPort);

	UFUNCTION(BlueprintCallable)
	virtual EPortSelectStatus Select(UFMDeviceCablePortComponent* PlayerSelectionPort, TArray<FPortUpdateInfo>& OutPortUpdates);

	UFUNCTION(BlueprintCallable)
	EPortSelectStatus SelectWithStaticOutputInteraction(UFMDeviceCablePortComponent* PlayerSelectionPort, TArray<FPortUpdateInfo>& OutPortUpdates);

	UFUNCTION(BlueprintPure)
	void SetCachedArtifact(const FFMDeviceCableArtifact& InCachedArtifact);

	UFUNCTION(BlueprintCallable)
	void SetDeviceCableAnimator(UFMDeviceCableAnimatorBase* InAnimator);

	UFUNCTION(BlueprintCallable)
	void SetPortActivatedState(EDeviceCableActivatedState NewActivatedState);

	UFUNCTION(BlueprintCallable)
	void SetPortConnectionsDirty();

	UFUNCTION(BlueprintCallable)
	void SetPortSelectableState(EDeviceCablePortSelectableState NewSelectableState);

	UFUNCTION(BlueprintCallable)
	void SetPortVisibility(bool bPortVisible);

	UPROPERTY(BlueprintAssignable)
	FFabricCablePortSizeUpdated OnCablePortSizeUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnAnimatorCreated OnAnimatorCreated;

	UPROPERTY(BlueprintAssignable)
	FOnConnected OnConnected;

	UPROPERTY(BlueprintAssignable)
	FOnDisconnected OnDisconnected;

	UPROPERTY(BlueprintAssignable)
	FOnConnectionStarted OnConnectionStarted;

	UPROPERTY(BlueprintAssignable)
	FOnConnectionEnded OnConnectionEnded;

	UPROPERTY(BlueprintAssignable)
	FOnPortArtifactUpdated OnPortArtifactUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnReceiveFloatProviders OnReceiveFloatProviders;

	UPROPERTY(BlueprintAssignable)
	FOnDisconnectFloatProvider OnDisconnectFloatProvider;

	UPROPERTY(EditAnywhere, Category="FMDeviceCablePortComponent")
	TSubclassOf<AActor> DeviceCableManagerClass;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool ActorHasValidControllerBP(AActor* Actor, AFortPlayerPawn*& OutFortPlayerPawn, APlayerController*& OutPlayerController);

	UFUNCTION(BlueprintCallable)
	void UpdateStaticMesh();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> OutputStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> AudioInStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> NoteInStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> TextureInStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> MeshInStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TSoftObjectPtr<UStaticMesh> ScalarInStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	TMap<EDeviceCablePortDataType, TSubclassOf<UFMDeviceCableAnimatorBase>> CableAnimatorClasses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EDeviceCablePortFlowType PortFlowType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EDeviceCablePortDataType PortDataType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EDeviceCableLoadableState PortLoadableState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EDeviceCablePortAnimationSyncType AnimationSyncType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FMDeviceCablePortComponent")
	bool bAllowMultipleConnections;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FMDeviceCablePortComponent")
	bool bAllowSiblingConnections;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EFMDeviceCablePortComponentAllowMultipleConnections OverrideAllowMultipleConnections;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	EFMDeviceCablePortComponentAllowMultipleConnections OverrideAllowSiblingConnections;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	bool bHideWhenNotRelevant;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	bool bIsPlayerPort;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FMDeviceCablePortComponent")
	bool bIsOnPreviewBuildingActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	FName EnterVolumeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCablePortComponent")
	FName ExitVolumeTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="FMDeviceCablePortComponent", meta=(EditInline="true"))
	TArray<UFMDeviceCablePortComponent*> ConnectedPorts;

	UPROPERTY(ReplicatedUsing=OnRep_ServerConnectedPorts, Export, meta=(EditInline="true"))
	TArray<UFMDeviceCablePortComponent*> ServerConnectedPorts;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FMDeviceCablePortComponent")
	TArray<UFMDeviceCableConnectionBase*> CurrentConnections;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ConstantCable, Category="FMDeviceCablePortComponent")
	AFMDeviceCable* ConstantCable;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DeviceCableManager, Export, meta=(EditInline="true"))
	UFMDeviceCableManagerComponent* DeviceCableManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UFMDeviceCablePortComponent*> OtherPortsOnActor;

	UPROPERTY(SaveGame)
	EDeviceCableActivatedState PortActivatedState;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_ServerPortActivatedState)
	EDeviceCableActivatedState ServerPortActivatedState;

	UPROPERTY(SaveGame, Replicated)
	EDeviceCablePortSelectableState PortSelectableState;

	UPROPERTY(Transient)
	UFMDeviceCableAnimatorBase* DeviceCableAnimator;

	UPROPERTY(Transient, SaveGame)
	FGuid ConnectionGuid;

	UPROPERTY(Transient, SaveGame)
	TArray<FGuid> ConnectedGuids;

	UPROPERTY()
	FFMDeviceCableArtifact CachedArtifact;

private:
	UFUNCTION()
	void OnPlayerControllerPortConnected(const TArray<UFMDeviceCablePortComponent*>& ControllerPorts);

	UFUNCTION()
	void OnPlayerControllerPortDisconnected();

	UFUNCTION()
	void OnRep_ConstantCable();

	UFUNCTION()
	void OnRep_DeviceCableManager();

	UFUNCTION()
	void OnRep_ServerConnectedPorts();

	UFUNCTION()
	void OnRep_ServerPortActivatedState();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UFMDeviceCablePortComponent*> PendingConnectionBroadcasts;

	UPROPERTY(VisibleAnywhere, Category="FMDeviceCablePortComponent")
	FGuid SaveGuid;

};

