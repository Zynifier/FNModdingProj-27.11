// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/Example/PFWExample_GameObject.h"
#include "PersistenceFramework/Example/ServiceWrapper/PFWExample_ServiceWrapper_ContainerInterface.h"
#include "PersistenceFramework/FortPersistenceFrameworkContainerInterface_InventoryService.h"
#include "PersistenceFramework/PersistenceFrameworkContainer.h"
#include "PFWExample_Container.generated.h"

USTRUCT()
struct FPFWExample_GameObject_PersistentInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 IntValue;

	UPROPERTY()
	float FloatValue;

	UPROPERTY()
	FString StringValue;

	UPROPERTY()
	FPFWExample_Struct StructValue;

	UPROPERTY()
	TArray<FPFWExample_Struct> StructArrayValue;

};

USTRUCT()
struct FPFWExample_GameObject_PersistentInfo_Version0
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 IntValue_1;

	UPROPERTY()
	int32 IntValue_2;

	UPROPERTY()
	float FloatValue;

	UPROPERTY()
	FString StringValue;

};

USTRUCT()
struct FPFWExample_SubGameObject_PersistentInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 IntValue;

};

UCLASS()
class FORTNITEGAME_API UPFWExample_Container : public UPersistenceFrameworkContainer, public IFortPersistenceFrameworkContainerInterface_InventoryService, public IPFWExample_ServiceWrapper_ContainerInterface
{
	GENERATED_BODY()

};

