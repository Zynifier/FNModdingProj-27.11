// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_RegisterCosmeticItemType.generated.h"

class UObject;

UCLASS(meta=(DisplayName="Register Cosmetic Item Type"))
class UFortGameFeatureAction_RegisterCosmeticItemType : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_RegisterCosmeticItemType", meta=(MustImplement="/Script/McpProfileSys.McpItemAware"))
	TSubclassOf<UObject> ItemClass;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_RegisterCosmeticItemType")
	FString ItemType;

};

