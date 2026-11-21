// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGlobals.h"
#include "FortGlobalActionDetailsDataSource.generated.h"

class UObject;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FFortGlobalActionDetailsDataSourceOnChangeDelegate, UObject*, Source);

UINTERFACE(BlueprintType)
class UFortGlobalActionDetailsDataSource : public UInterface
{
	GENERATED_BODY()
};

class IFortGlobalActionDetailsDataSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Name")
	void AddOnChangeDelegate(const FFortGlobalActionDetailsDataSourceOnChangeDelegate& InDelegate);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Name", meta=(CompactNodeTitle="Value"))
	FFortGlobalActionDetails GetValue() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Name")
	void RemoveOnChangeDelegate(const FFortGlobalActionDetailsDataSourceOnChangeDelegate& InDelegate);

};

