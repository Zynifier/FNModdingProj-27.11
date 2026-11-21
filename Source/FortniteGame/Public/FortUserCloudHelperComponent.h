// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortUserCloudHelperComponent.generated.h"

UENUM()
enum class EFortUserCloudRequestResult : uint8
{
	Success = 0,
	Failure_CloudStorageDisabled = 1,
	Failure_CloudStorageError = 2,
	Failure_FileNotFoundInUserFileList = 3,
	Failure_SavingNotAllowedForSpecifiedUser = 4,
};

UENUM()
enum class EFortUserCloudRequestType : uint8
{
	LoadCloudFile = 0,
	SaveCloudFile = 1,
};

USTRUCT()
struct FFortUserCloudRequestHandle
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint64 Handle;

};

USTRUCT()
struct FFortUserCloudRequestPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortUserCloudRequestHandle RequestHandle;

	UPROPERTY()
	FUniqueNetIdRepl UserNetID;

	UPROPERTY()
	FString Filename;

	UPROPERTY()
	EFortUserCloudRequestType RequestType;

	UPROPERTY()
	TArray<uint8> DataBuffer;

};

USTRUCT()
struct FFortUserCloudRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortUserCloudRequestPayload RequestPayload;

	UPROPERTY()
	uint8 bNeedsFileEnumeration : 1;

	UPROPERTY()
	uint8 bStartedProcessing : 1;

};

USTRUCT()
struct FFortUserCloudRequestQueue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bFreezeIncomingRequests : 1;

	UPROPERTY()
	FFortUserCloudRequestHandle FirstFrozenHandle;

	UPROPERTY()
	FTimerHandle ProcessingTimerHandle;

	UPROPERTY()
	TArray<FFortUserCloudRequest> RequestQueue;

};

UCLASS()
class UFortUserCloudHelperComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint64 LastIssuedRequestHandle;

	UPROPERTY(Config)
	int32 SaveSizeCompressionThreshold;

};

