// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "McpProfileRequestTypes.generated.h"

USTRUCT()
struct MCPPROFILESYS_API FMcpAddItemRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	int32 Quantity;

	UPROPERTY()
	FJsonObjectWrapper Attributes;

};

USTRUCT()
struct MCPPROFILESYS_API FMcpChangeAttributesRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	FJsonObjectWrapper Attributes;

};

USTRUCT()
struct MCPPROFILESYS_API FMcpChangeQuantityRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	int32 DeltaQuantity;

};

USTRUCT()
struct MCPPROFILESYS_API FMcpRemoveItemRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

};

USTRUCT()
struct MCPPROFILESYS_API FMcpProfileChangeRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BaseCommandRevision;

	UPROPERTY()
	TArray<FMcpAddItemRequest> AddRequests;

	UPROPERTY()
	TArray<FMcpRemoveItemRequest> RemoveRequests;

	UPROPERTY()
	TArray<FMcpChangeQuantityRequest> ChangeQuantityRequests;

	UPROPERTY()
	TArray<FMcpChangeAttributesRequest> ChangeAttributesRequests;

	UPROPERTY()
	TArray<FJsonObjectWrapper> ChangeStatRequests;

};

