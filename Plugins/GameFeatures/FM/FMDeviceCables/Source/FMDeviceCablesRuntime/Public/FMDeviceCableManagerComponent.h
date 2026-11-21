// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "FMDeviceCableConnection.h"
#include "FMDeviceCableTypes.h"
#include "GameplayEventRouterTypes.h"
#include "FMDeviceCableManagerComponent.generated.h"

class AFMDeviceCable;
class UFMDeviceCableConnectionBase;
class UFMDeviceCablePortComponent;
class UObject;
class USoundSourceBus;
enum class EDeviceCableInteractionType : uint8;

UENUM(BlueprintType)
enum class EDeviceCableInteractionType : uint8
{
	Free = 0,
	// Cables are created as needed to connect to ports

	StaticOutput = 1,
};

USTRUCT(BlueprintType)
struct FFMDeviceCableActiveConnectionsList
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<UFMDeviceCableConnectionBase*> ActiveConnections;

};

USTRUCT(BlueprintType)
struct FFMDeviceCableTopologyNode
{
	GENERATED_BODY()

public:
	UPROPERTY(Export)
	TWeakObjectPtr<UFMDeviceCablePortComponent> Port;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMDEVICECABLESRUNTIME_API UFMDeviceCableManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	EDeviceCableInteractionType GetCableInteractionType();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableManagerComponent")
	TSubclassOf<AFMDeviceCable> DeviceCableClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableManagerComponent")
	int32 StartingCablePoolSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableManagerComponent")
	EDeviceCableInteractionType CableInteractionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableManagerComponent")
	TMap<EDeviceCablePortDataType, TSubclassOf<UFMDeviceCableConnectionBase>> ConnectionClasses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableManagerComponent")
	TObjectPtr<USoundSourceBus> DefaultSourceBus;

	UPROPERTY(Transient)
	FGameplayEventListenerBackwardCompatibleHandle PlayerEnteredHandle;

private:
	UPROPERTY(Replicated)
	TArray<AFMDeviceCable*> FreeDeviceCables;

	UPROPERTY(Transient)
	TArray<UFMDeviceCableConnectionBase*> CableConnections;

	UPROPERTY(Transient, Export)
	TMap<FGuid, TWeakObjectPtr<UFMDeviceCablePortComponent>> PortsInVolume;

	UPROPERTY(Transient)
	TMap<FGuid, FGuid> OriginalGuidToDuplicatedGuidThisFrame;

	UPROPERTY(Transient)
	TMap<TSoftObjectPtr<UObject>, TSoftObjectPtr<UObject>> SourceObjectToDuplicatedObjectThisFrame;

	UPROPERTY()
	FFMDeviceCableDefaultOutputs DefaultConnectionOutputs;

};

