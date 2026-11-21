// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FMDeviceCableConnection.generated.h"

class AActor;
class UFMDeviceCablePortComponent;
class USoundSourceBus;

USTRUCT(BlueprintType)
struct FFMDeviceCablePassthroughDeviceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FMDeviceCablePassthroughDeviceInfo")
	TWeakObjectPtr<UFMDeviceCablePortComponent> InputPort;

	UPROPERTY(BlueprintReadOnly, Export, Category="FMDeviceCablePassthroughDeviceInfo")
	TWeakObjectPtr<UFMDeviceCablePortComponent> OutputPort;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCablePassthroughDeviceInfo")
	TWeakObjectPtr<AActor> PassthroughActor;

};

USTRUCT(BlueprintType)
struct FFMDeviceCableTerminalDeviceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FMDeviceCableTerminalDeviceInfo")
	TWeakObjectPtr<UFMDeviceCablePortComponent> TerminalPort;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableTerminalDeviceInfo")
	TWeakObjectPtr<AActor> TerminalActor;

};

USTRUCT(BlueprintType)
struct FFMDeviceCableConnectedDevicesInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableConnectedDevicesInfo")
	FFMDeviceCableTerminalDeviceInfo SourceDeviceInfo;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableConnectedDevicesInfo")
	FFMDeviceCableTerminalDeviceInfo DestinationDeviceInfo;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableConnectedDevicesInfo")
	TArray<FFMDeviceCablePassthroughDeviceInfo> PassthroughDeviceInfos;

};

USTRUCT(BlueprintType)
struct FFMDeviceCableDefaultOutputs
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<USoundSourceBus> SourceBus;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableConnectionBase : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="EndConnection"))
	void EndConnectionBP();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="StartConnection"))
	void RebuildDirtyConnectionBP();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="StartConnection"))
	void StartConnectionBP();

	UPROPERTY(Transient)
	bool bConnectionActive;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFMDeviceCablePortComponent>> BuildingCompositeArtifactFromPorts;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableConnectionBase")
	FFMDeviceCableConnectedDevicesInfo ConnectedDevicesInfo;

	UPROPERTY(Transient)
	FFMDeviceCableDefaultOutputs DefaultOutputs;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableMetaSoundConnection : public UFMDeviceCableConnectionBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAudioConnection : public UFMDeviceCableMetaSoundConnection
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableFloatConnection : public UFMDeviceCableConnectionBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableMeshConnection : public UFMDeviceCableConnectionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	uint32 PreviousMeshInstanceHash;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableNoteConnection : public UFMDeviceCableMetaSoundConnection
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableTextureConnection : public UFMDeviceCableConnectionBase
{
	GENERATED_BODY()

};

