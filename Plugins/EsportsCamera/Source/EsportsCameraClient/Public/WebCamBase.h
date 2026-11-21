// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WebCamBase.generated.h"

class UMaterialInstanceDynamic;
class UTexture2D;

UCLASS()
class ESPORTSCAMERACLIENT_API AWebCamBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UTexture2D> DynamicTexture;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;

	UPROPERTY()
	TArray<uint8> DynamicColors;

};

