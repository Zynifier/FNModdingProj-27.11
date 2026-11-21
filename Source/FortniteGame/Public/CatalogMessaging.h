// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CatalogMessaging.generated.h"

UCLASS(MinimalAPI)
class UCatalogMessaging : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CatalogMessaging")
	TMap<FString, FText> StoreToast_Header;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CatalogMessaging")
	TMap<FString, FText> StoreToast_Body;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CatalogMessaging")
	TMap<FString, FText> Banners;

};

