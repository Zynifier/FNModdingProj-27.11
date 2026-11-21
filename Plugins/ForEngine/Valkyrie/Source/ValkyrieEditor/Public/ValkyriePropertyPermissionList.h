// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyriePropertyPermissionList.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FValkyriePropertyPermissionList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	TArray<FName> AllowList;

	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	TArray<FName> DenyList;

	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	bool bAllowListAllProperties;

	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	bool bAllowListAllSubclassProperties;

};

USTRUCT(BlueprintType)
struct FValkyrieClassPropertyPermissionList : public FValkyriePropertyPermissionList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	TSoftClassPtr<UObject> Type;

};

USTRUCT(BlueprintType)
struct FValkyrieStructPropertyPermissionList : public FValkyriePropertyPermissionList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyEditor")
	TObjectPtr<UObject> Type;

};

