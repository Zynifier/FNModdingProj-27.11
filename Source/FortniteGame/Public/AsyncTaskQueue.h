// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AsyncTaskQueue.generated.h"

USTRUCT(BlueprintType)
struct FAsyncTaskResult
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="AsyncTaskResult")
	bool bSucceeded;

	UPROPERTY(BlueprintReadOnly, Category="AsyncTaskResult")
	FString ErrorCode;

	UPROPERTY(BlueprintReadOnly, Category="AsyncTaskResult")
	FText ErrorMessage;

};

UCLASS()
class UAsyncTaskQueue : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnAsyncTaskFinished(const FAsyncTaskResult& Result);

};

