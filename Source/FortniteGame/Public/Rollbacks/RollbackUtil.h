// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RollbackUtil.generated.h"

USTRUCT(BlueprintType)
struct FCvarRollback
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CvarRollback")
	FName RollbackCvar;

	UPROPERTY(BlueprintReadOnly, Category="CvarRollback")
	bool State;

	UPROPERTY(BlueprintReadOnly, Category="CvarRollback")
	FName Category;

	UPROPERTY(BlueprintReadOnly, Category="CvarRollback")
	FString Jiras;

	UPROPERTY(BlueprintReadOnly, Category="CvarRollback")
	FString Description;

};

UCLASS()
class URollbackUtilBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	static TArray<FCvarRollback> GetRollbacksByCategories(const FString Category);

	UFUNCTION(BlueprintCallable)
	static TArray<FCvarRollback> GetRollbacksByJiraTicket(const FString JiraTicket);

};

