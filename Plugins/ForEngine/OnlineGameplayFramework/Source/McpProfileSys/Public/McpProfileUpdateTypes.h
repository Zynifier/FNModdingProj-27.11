// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "McpProfileUpdateTypes.generated.h"

USTRUCT()
struct FProfileUpdateSingle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 ProfileRevision;

	UPROPERTY()
	FString ProfileId;

	UPROPERTY()
	int64 ProfileChangesBaseRevision;

	UPROPERTY()
	TArray<FJsonObjectWrapper> ProfileChanges;

	UPROPERTY()
	FDateTime LockExpiration;

	UPROPERTY()
	TArray<FJsonObjectWrapper> Notifications;

	UPROPERTY()
	int32 ProfileCommandRevision;

};

USTRUCT()
struct FProfileUpdate : public FProfileUpdateSingle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ResponseVersion;

	UPROPERTY()
	FDateTime ServerTime;

	UPROPERTY()
	TArray<FProfileUpdateSingle> MultiUpdate;

};

USTRUCT()
struct FAccountIdAndProfileResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	FProfileUpdate Response;

};

USTRUCT()
struct FProfileUpdateNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FJsonObjectWrapper> Changes;

	UPROPERTY()
	FDateTime LockExpiration;

	UPROPERTY()
	int32 CommandRevision;

	UPROPERTY()
	int64 Revision;

};

