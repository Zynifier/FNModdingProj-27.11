// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "UpdateManager.h"
#include "FortUpdateManager.generated.h"

class UFortAsyncAction_CheckForUpdate;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateCheckDelegate);

UCLASS()
class UFortAsyncAction_CheckForUpdate : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UpdateManager", meta=(BlueprintInternalUseOnly="true", WorldContext="InWorldContextObject"))
	static UFortAsyncAction_CheckForUpdate* CheckForUpdate(UObject* InWorldContextObject, bool InShowDialogOnFailure = true);

	UPROPERTY(BlueprintAssignable)
	FUpdateCheckDelegate OnUpToDate;

	UPROPERTY(BlueprintAssignable)
	FUpdateCheckDelegate OnUpdateRequired;

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY()
	bool bShowDialogOnFailure;

};

UCLASS(MinimalAPI)
class UFortUpdateManager : public UUpdateManager
{
	GENERATED_BODY()

};

