// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "UObject/SoftObjectPath.h"
#include "ValkyrieAssetAdapterActorFactory.generated.h"

USTRUCT()
struct FAssetAdapterInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AssetAdapterInfo")
	FSoftClassPath AssetClassPath;

	UPROPERTY(EditAnywhere, Category="AssetAdapterInfo")
	FSoftClassPath AdaptedClassPath;

	UPROPERTY(EditAnywhere, Category="AssetAdapterInfo")
	FString AdaptedPropertyName;

};

UCLASS(HideCategories=("Object"))
class UValkyrieAssetAdapterActorFactory : public UActorFactory
{
	GENERATED_BODY()

};

