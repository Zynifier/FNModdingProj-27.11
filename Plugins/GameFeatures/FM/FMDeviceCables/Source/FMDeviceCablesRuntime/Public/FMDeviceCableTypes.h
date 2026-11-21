// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FMDeviceCableTypes.generated.h"

class UFMDeviceCablePortComponent;
class UFabricMeshTreeNode;
class UFabricMetaSoundTreeNode;
class UFabricModulationNode;
class UFabricTextureTreeNode;

UENUM(BlueprintType)
enum class EDeviceCableActivatedState : uint8
{
	Active = 0,
	Dormant = 1,
};

UENUM(BlueprintType)
enum class EDeviceCablePortDataType : uint8
{
	Scalar = 0,
	Note = 1,
	Audio = 2,
	Texture = 3,
	Mesh = 4,
	Any = 5,
};

UENUM(BlueprintType)
enum class EDeviceCablePortFlowType : uint8
{
	Input = 0,
	Output = 1,
	Any = 2,
};

UENUM(BlueprintType)
enum class EPortSelectStatus : uint8
{
	Error = 0,
	ControllerCableUsed = 1,
	GaveControllerCable = 2,
	CableSwap = 3,
	NewCableUsed = 4,
	ConstantCableUsed = 5,
	ConnectionEnded = 6,
	NoCableAvailable = 7,
	TypeMismatch = 8,
	AttemptedMultiConnect = 9,
	SelfSelect = 10,
	InvalidConnection = 11,
	WouldCreateLoop = 12,
	Unselectable = 13,
};

USTRUCT(BlueprintType)
struct FFMDeviceCableArtifact
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	UFabricMeshTreeNode* MeshTreeNode;

	UPROPERTY(Transient)
	UFabricMetaSoundTreeNode* MetaSoundTreeNode;

	UPROPERTY(Transient)
	UFabricTextureTreeNode* TextureTreeNode;

	UPROPERTY(Transient)
	UFabricModulationNode* ModulationNode;

};

USTRUCT(BlueprintType)
struct FPortUpdateInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EPortSelectStatus PortSelectStatus;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* ConstantPort;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* ConnectedPort;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* DisconnectedPort;

};

