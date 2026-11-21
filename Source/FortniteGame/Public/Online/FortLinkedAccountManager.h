// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortLinkedAccountManager.generated.h"

class UFortLinkedAccount;
class UFortLinkedAccountManager;

UCLASS(Abstract)
class UFortLinkedAccount : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortLinkedAccountManager> Manager;

};

UCLASS()
class UFortLinkedAccountManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortLinkedAccount>> LinkedAccounts;

};

