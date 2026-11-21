// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MotherGameplayTypes.generated.h"

class APlayerState;

USTRUCT(BlueprintType)
struct FPaddleGingerPropActivatedData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropActivatedData")
	bool bActivated;

	UPROPERTY(BlueprintReadWrite, Transient, Category="PaddleGingerPropActivatedData")
	TObjectPtr<APlayerState> Sender;

};

USTRUCT(BlueprintType)
struct FPaddleGingerPropData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropData")
	FText CategoryLabelText;

	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropData")
	int32 PropIndex;

	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropData")
	int32 MaxPropCount;

	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropData")
	int32 CategoryIndex;

	UPROPERTY(BlueprintReadWrite, Category="PaddleGingerPropData")
	int32 MaxCategoryCount;

	UPROPERTY(BlueprintReadWrite, Transient, Category="PaddleGingerPropData")
	TWeakObjectPtr<APlayerState> Sender;

};

